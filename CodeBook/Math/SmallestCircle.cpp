#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010
#define eps 1e-6
const double PI = acos(-1.0);

class Point;
class LineEquation;

double sqr(double x) {
	return x * x;
}

struct LineEquation {
	double a, b, c;
	LineEquation(){}
	LineEquation(double _a, double _b, double _c) {
		a = _a; b = _b; c = _c; 
	}
	
	Point getCrossPoint(const LineEquation& other);
	double getXByY(double y) const{
		return - (b*y + c) / a;
	}
};

struct Point {
	double x, y;
	Point(){}
	Point(double _x, double _y) : x(_x), y(_y) {
	}
	void read() {
		scanf("%lf %lf", &x, &y);
	}
	Point operator+(const Point& other) const {
		return Point(x + other.x, y + other.y);
	}
	Point operator-(const Point& other) const {
		return Point(x - other.x, y - other.y);
	}
	double operator*(const Point& other) const {
		return x * other.x + y * other.y;
	}
	Point operator/(double k) const {
		return Point(x/k, y/k);
	}
	double len() const {
		return sqrt(len_sqr());
	}
	double len_sqr() const {
		return sqr(x)+sqr(y);
	} 
	double dist(const Point& other) const {
		return (*this - other).len();
	}
	Point centerWith(const Point& other) const {
		return (*this + other) / 2;
	}

	double getAngle(const Point& A, const Point& B) {
		Point OA = (A-*this);
		Point OB = (B-*this);
		return acos(OA*OB/OA.len()/OB.len());
	}
	
	void print() {
		printf("%lf %lf\n", x, y);
	}
	
	Point getExcenter(const Point& A, const Point& B) {
		double agl = getAngle(A, B);
		if( fabs(agl-PI) < eps ) {
			return (A+B)/2;
		}else if( fabs(agl) < eps ) {
			return dist(A)>dist(B) ? centerWith(A) : centerWith(B);
		}
		Point OA = A - *this;
		Point OB = B - *this;
		LineEquation L1(2*OA.x, 2*OA.y, len_sqr()-A.len_sqr());
		LineEquation L2(2*OB.x, 2*OB.y, len_sqr()-B.len_sqr());
		if(fabs(L1.a) < eps) {
			return L1.getCrossPoint(L2);
		}
		return L2.getCrossPoint(L1);
	}
};

Point LineEquation::getCrossPoint(const LineEquation& other){
	Point ans;
	if(fabs(a) < eps) {
		ans.y = -c/b;
	}else {
		ans.y = (other.a*c - a*other.c) / (a*other.b - other.a*b);
	}
	ans.x = other.getXByY(ans.y);
	return ans;
}

struct Circle {
	Point center;
	double radius;

	Circle(){}
	Circle(Point c, double r): center(c), radius(r){}

	bool isPointInCircle(const Point& pt) {
		return (pt - center).len() <= radius;
	}
};

struct PointSet {
	int n;
	Point p[MAXN];

	// 隨機增量法，打亂所有點的順序
	void randomSuffle() {
		int i;
		for(i = 0; i < n; ++i) {
			int ridx = rand() % n;
			Point tmp = p[i];
			p[i] = p[ridx];
			p[ridx] = tmp;
		}
	}

	// 包含二點的最小圓
	Circle getMinCircleInclude2(int idx1, int idx2) {
		int i;
		Point nowc = (p[idx1] + p[idx2]) / 2;
		double nowr = (nowc - p[idx2]).len(); 
		Circle now(nowc, nowr);
		
		for(i = 0; i < idx1; ++i) {
			if(!now.isPointInCircle(p[i])) {
				Point nextc = p[i].getExcenter(p[idx1], p[idx2]);
				double nextr = (nextc - p[idx2]).len();
				if(nextr > nowr) {
					nowc = nextc;
					nowr = nextr;
					now = Circle(nowc, nowr);
				}				
			}
		}
		return now;
	}

	// 包含一個點的最小圓
	Circle getMinCircleInclude1(int idx) {
		Circle now(p[idx], 0);

		for(int i = 0; i < idx; ++i) {
			if(!now.isPointInCircle(p[i])) {
				now = getMinCircleInclude2(i, idx);
			}
		}
		return now;
	}
	
	// 最小圓
	Circle getMinCircle() {
		randomSuffle();
		
		Circle now(p[0], 0);
		for(int i = 1; i < n; ++i) {
			if(!now.isPointInCircle(p[i])) {
				now = getMinCircleInclude1(i);
			}
		}
		return now;
	}
}ps;

int main() {
	int t;
	int i;
	while( ~scanf("%d", &ps.n) ) {
		for(i = 0; i < ps.n; ++i) {
			ps.p[i].read();
		}
		Circle c = ps.getMinCircle();
		printf("%.2lf %.2lf %.2lf\n", c.center.x, c.center.y, c.radius);
	}
	return 0;
}