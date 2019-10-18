#include <stdio.h>
//ax == 1 (mod m),求x
struct gcdstruct {
    int d;
    int x;
    int y;
};

gcdstruct EXTENDED_EUCLID(int a, int b) {
    gcdstruct aa, bb;
    if (b == 0) {
        aa.d = a;
        aa.x = 1;
        aa.y = 0;
        return aa;
    } else {
        bb = EXTENDED_EUCLID(b, a % b);
        aa.d = bb.d;
        aa.x = bb.y;
        aa.y = bb.x - bb.y * (a / b);
    }
    return aa;
}


 int inverse(int a, int m) {
     int x;
     gcdstruct aa;
     aa = EXTENDED_EUCLID(a, m);
     return aa.x;
 }
 int main() {
     int a, m;
     scanf("%d %d",&a,&m);
     
     printf("%d\n",inverse(a, m));
     getchar();
     return 0;
 }