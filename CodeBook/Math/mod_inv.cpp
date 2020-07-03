#include <stdio.h>
#define LL long long
const LL maxn(1000005), mod(1000000000 + 7);
//ax == 1 (mod m),query x -> use exgcd
//if m is prime ,than x = a^(p-2) % p

LL inv[maxn]; //for mod_inv table
LL Jc[maxn];  //for factorial table
void calJc()    //factorial table
{
    Jc[0] = Jc[1] = 1;
    for(LL i = 2; i < maxn; i++)
        Jc[i] = Jc[i - 1] * i % mod;
}

//section 1 for exgcd start
void exgcd(LL a, LL b, LL &x, LL &y)
{
    if(!b) x = 1, y = 0;
    else
    {
        exgcd(b, a % b, y, x);
        y -= x * (a / b);
    }
}
LL niYuan(LL a, LL b)//ax+by = 1
{
    LL x, y;
    exgcd(a, b, x, y);
    return (x + b) % b;
}
//section 1 for exgcd end

//section 2 for fema's theorem start
LL pow(LL a, LL n, LL p)    // a^n % p
{
    LL ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}
// LL niYuan(LL a, LL b)   //if mod(b) is prime we use fema's theorem
// {
//     return pow(a, b - 2, b);
// }
// // section 2 for fema's theorem end

//section 3 for tableing inverse start
void mod_inv_table(){
    inv[1]=1;
    for (int i = 2; i < maxn; ++i)
    {
        inv[i] = (mod-mod/i)*inv[mod%i] %mod;
    }
}
//section 3 for tableing end

LL C(LL a, LL b)    //cac C(a, b)
{
    // printf("Jc[%lld] = %lld\n",a,Jc[a] );
    return Jc[a] * niYuan(Jc[b], mod) % mod
        * niYuan(Jc[a - b], mod) % mod;
}

int main(int argc, char const *argv[])
{
    calJc();    //if need cac C(a,b)
    // printf("%lld\n",C(1000,2) );
    mod_inv_table();    //if need table of mod_inv from 1~mod-1
    return 0;
}
