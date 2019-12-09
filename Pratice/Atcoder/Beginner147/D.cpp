#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= z; x++)
#define REPP(x, y, z) for(int x = y; x >= z; x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn


//structure

//declaration
ll lis[300005];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;
	scanf("%d\n", &n);


	ll mod = 1000000007;

	REP(i, 1, n)
		scanf("%lld", &lis[i]);

	ll ans = 0;
	ll odd, even;

	for(ll i = 0; i < 60; i++)
	{
		odd = even = 0;
		REP(j, 1, n)
		{	
			if(lis[j]&1LL<<i)
				odd++;
			else
				even++;
		}

		ans = (ans + (((odd*even)%mod)*((1LL<<i)%mod))%mod)%mod;
	}


	printf("%lld\n", (ll)(ans%mod));

	return 0;
}