#include <bits/stdc++.h>
using namespace std;
#define N 10
// P為平面上散佈的點。設定為N點。
// CH為凸包上的頂點。設定為逆時針方向排列。可以視作一個stack。
struct Point {int x, y;} P[N], CH[N+1];
 
// 向量OA叉積向量OB。大於零表示從OA到OB為逆時針旋轉。
double cross(Point o, Point a, Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
 
// 小於。依座標大小排序，先排 x 再排 y。
bool compare(Point a, Point b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

int Andrew_monotone_chain()
{
    // 將所有點依照座標大小排序
    sort(P, P+N, compare);
 
    int m = 0;  // m 為凸包頂點數目
 
    // 包下半部
    for (int i=0; i<N; ++i)
    {
        while (m >= 2 && cross(CH[m-2], CH[m-1], P[i]) <= 0) m--;
        CH[m++] = P[i];
    }
 
    // 包上半部，不用再包入剛才包過的終點，但會再包一次起點
    for (int i=N-2, t=m+1; i>=0; --i)
    {
        while (m >= t && cross(CH[m-2], CH[m-1], P[i]) <= 0) m--;
        CH[m++] = P[i];
    }
    m--;    // 最後一個點是重複出現兩次的起點，故要減一。

    return m;
}

double cac_area(int m){ //有m個點
    double re=0.0,t=0.0;
    while(m>=2)
    {
        t = cross( CH[0] ,CH[m-1], CH[m-2])/2.0;
        if(t<0) t=-t;
        m--;
        re=re+t;
    }
    return re;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}