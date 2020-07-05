#include <bits/stdc++.h>
using namespace std;
#define PROBLEM "10225"
#define LL long long
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

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

int main(int argc, char const *argv[])
{
	LL P,A,B; //query i that A^i := B (mod P)
	while(cin>>P>>A>>B){
		LL sqp = sqrt(P);
		map <LL,int> m;
		bool fians = false;
		LL t = 1;
		for (int i = 0; i < sqp; ++i) //baby step
		{
			if (t==B)
			{
				printf("%d\n",i );
				fians = true;
				break;
			}
			m[t]=i+1; //bcz case i=0
			t = t*A % P;
		}
		if (fians)
			continue;
		fians = false;

		LL inv_an = pow(t,P-2,P);
		t = inv_an*B % P;
		//assume A^(i*n+k):=B -> A^k := B*A*(a^n)^-i
		for (int i = 1; i <= sqp; ++i) //giant step
		{
			int te = m[t % P];
			if (te!=0)
			{
				printf("%d\n",i*sqp+(te-1) );
				fians = true;
				break;
			}
			t = t*inv_an % P;
		}
		if (!fians)
		{
			printf("no solution\n");
		}
	}
	return 0;
}
