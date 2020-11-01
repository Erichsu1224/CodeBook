#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010
#define eps 1e-6
const double PI = acos(-1.0);

double sqr(double x) {
	return x * x;
}

#define MAXL 5

class GaussMatrix {
public:
    int r, c;
    double d[MAXL][MAXL];
    double x[MAXL];
    
    void swap_row(int ra, int rb) {
        int i;
        for(i = 0; i <= c; i++) {
            double tmp = d[ra][i];
            d[ra][i] = d[rb][i];
            d[rb][i] = tmp;
            
        }
    }
    
    bool zero(double v) {
        return fabs(v) < eps;
    }
    
    bool gauss() {
        int i, j, k;
        int col = 0;
        int maxrow;
        
        for(i = 0; i < r && col < c; i++) {
            maxrow = i;
            for(j = i+1; j < r; j++) {
                if( fabs(d[j][col]) > fabs(d[maxrow][col]) ) {
                    maxrow = j;
                }
            }

            if(i != maxrow) swap_row(i, maxrow);

            if( zero(d[i][col]) ) {
                col ++;
                i --;
                continue;
            }
            for(j = i+1; j < r; j++) {

                if( !zero(d[j][col]) ) {
                    double sub = d[j][col]/d[i][col];
                    for(k = col; k <= c; k++) {
                        d[j][k] = d[j][k] - d[i][k] * sub;
                    }
                }
            }
            col++;
        }
        
        for(i = c-1; i >= 0; i--) {
            double sum = 0;
            for(j = i+1; j < c; j++) {
                sum += x[j] * d[i][j];
            }
            x[i] = (d[i][c] - sum) / d[i][i];
            if( zero(x[i]) ) x[i] = 0;
        }
        return true;
    }
};

struct PlaneParameter {
	// Ax + By + Cz + D = 0
	double A, B, C, D;
	
	PlaneParameter() {}
	PlaneParameter(double _A, double _B, double _C, double _D) {
		A = _A;
		B = _B;
		C = _C;
		D = _D;
	}
};

struct Point {
	double x, y, z;
	Point(){}
	Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
	void read() {
		scanf("%lf %lf %lf", &x, &y, &z);
	}
	Point operator+(const Point& other) const {
		return Point(x + other.x, y + other.y, z + other.z);
	}
	Point operator-(const Point& other) const {
		return Point(x - other.x, y - other.y, z - other.z);
	}
	double operator*(const Point& other) const {
		return x * other.x + y * other.y + z * other.z;
	}
	Point operator/(double k) const {
		return Point(x/k, y/k, z/k);
	}
	Point X(const Point& other) const {
		return Point(y*other.z - z*other.y,
		             z*other.x - x*other.z,
		             x*other.y - y*other.x);
	}
	
	double len() const {
		return sqrt(len_sqr());
	}
	double len_sqr() const {
		return sqr(x) + sqr(y) + sqr(z);
	} 
	double dist(const Point& other) const {
		return (*this - other).len();
	}
	Point centerWith(const Point& other) const {
		return (*this + other) / 2;
	}
	
	void print() {
		printf("%lf %lf %lf\n", x, y, z);
	}
	
	Point getExcenter(const Point& A, const Point& B) {
		Point OA = A - *this;
		Point OB = B - *this;
		PlaneParameter P[3];
		P[0] = PlaneParameter(2*OA.x, 2*OA.y, 2*OA.z, len_sqr()-A.len_sqr());
		P[1] = PlaneParameter(2*OB.x, 2*OB.y, 2*OB.z, len_sqr()-B.len_sqr());
		// 法向量 
		Point N = OA.X(OB);
		P[2] = PlaneParameter(N.x, N.y, N.z, -(N * A));
		
		GaussMatrix gm;
		gm.r = gm.c = 3;
		for(int i = 0; i < 3; ++i) {
			gm.d[i][0] = P[i].A;
			gm.d[i][1] = P[i].B;
			gm.d[i][2] = P[i].C;
			gm.d[i][3] = -P[i].D;
		}
		gm.gauss();
		return Point(gm.x[0], gm.x[1], gm.x[2]);
	}
	
	Point getBallCenter(const Point& A, const Point& B, const Point& C) {
		Point OA(A - *this), OB(B - *this), OC(C - *this);
		PlaneParameter P[3];
		P[0] = PlaneParameter(2*OA.x, 2*OA.y, 2*OA.z, len_sqr()-A.len_sqr());
		P[1] = PlaneParameter(2*OB.x, 2*OB.y, 2*OB.z, len_sqr()-B.len_sqr());
		P[2] = PlaneParameter(2*OC.x, 2*OC.y, 2*OC.z, len_sqr()-C.len_sqr());
		
		GaussMatrix gm;
		gm.r = gm.c = 3;
		for(int i = 0; i < 3; ++i) {
			gm.d[i][0] = P[i].A;
			gm.d[i][1] = P[i].B;
			gm.d[i][2] = P[i].C;
			gm.d[i][3] = -P[i].D;
		}
		gm.gauss();
		return Point(gm.x[0], gm.x[1], gm.x[2]);
	} 
}; 

struct Ball {
	Point center;
	double radius;

	Ball(){}
	Ball(Point c, double r): center(c), radius(r) {}

	bool isPointInBall(const Point& pt) {
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
	
	// 包含三點的球
	Ball getMinBallInclude3(int idx1, int idx2, int idx3) {
		int i;
		Point nowc = p[idx1].getExcenter(p[idx2], p[idx3]);
		double nowr = (nowc - p[idx3]).len();
		Ball now(nowc, nowr);
		for(i = 0; i < idx1; ++i) {
			if(!now.isPointInBall(p[i])) {
				Point nextc = p[i].getBallCenter(p[idx1], p[idx2], p[idx3]);
				double nextr = (nextc - p[idx3]).len();
				if(nextr > nowr) {
					nowc = nextc;
					nowr = nextr;
					now = Ball(nowc, nowr);
				}
			}
		}
		return now;
	}

	// 包含二點的球
	Ball getMinBallInclude2(int idx1, int idx2) {

		Point nowc = p[idx1].centerWith(p[idx2]);
		double nowr = (nowc - p[idx2]).len();
		Ball now(nowc, nowr);
		
		for(int i = 0; i < idx1; ++i) {
			if(!now.isPointInBall(p[i])) {
				now = getMinBallInclude3(i, idx1, idx2);			
			}
		}
		return now;
	}

	// 包含一點的球
	Ball getMinBallInclude1(int idx) {

		Ball now(p[idx], 0);

		for(int i = 0; i < idx; ++i) {
			if(!now.isPointInBall(p[i])) {
				now = getMinBallInclude2(i, idx);
			}
		}
		return now;
	}
	
	// 最小球
	Ball getMinBall() {
		randomSuffle();
		
		Ball now(p[0], 0);
		for(int i = 1; i < n; ++i) {
			if(!now.isPointInBall(p[i])) {
				now = getMinBallInclude1(i);
			}
		}
		return now;
	}
}ps;

int main() {
	int t;
	int i;
	while( scanf("%d", &ps.n) != EOF && ps.n ) {
		for(i = 0; i < ps.n; ++i) {
			ps.p[i].read();
		}
		Ball c = ps.getMinBall();
		c.center.print();
		printf("%.7lf\n", c.radius);
	}
	return 0;
}
