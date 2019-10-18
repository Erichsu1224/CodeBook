#include <bits/stdc++.h>
#define ll long long
//ax+by==gcd(a,b)
//ax+by==1
//ax+by==c
ll gcdEx(ll a, ll b, ll &x, ll &y) 
{
    if(b==0)
    {
        x = 1,y = 0;
        return a;
    }
    else
    {
        ll r = gcdEx(b, a%b, x, y); /* r = GCD(a, b) = GCD(b, a%b) */
        ll t = x;
        x = y;
        y = t - a/b * y;
        return r;
    }
}
void extendex(ll m,ll n ,ll &x, ll &y ){
  //printf("%d %d %d %d\n",m,n,x,y );
  x%=n;
  y%=m;
}
int main(int argc, char const *argv[])
{
   ll m,m_ans,n,n_ans,c;
   scanf("%lld %lld %lld",&m,&n,&c);
   m_ans=m;
   n_ans=n;
   gcdEx(m,n,m_ans,n_ans);
   m_ans*=c;
   n_ans*=c;
   extendex(m,n,m_ans,n_ans);
   printf("%lld %lld\n",m_ans,n_ans );
   return 0;
}