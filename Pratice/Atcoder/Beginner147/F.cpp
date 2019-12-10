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
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	ll n, x, d;

	cin >> n >> x >> d;

	if(d == 0)
	{
		if(x == 0)
			printf("1\n");
		else
			cout << 1+n << '\n';
	}

	else
	{
		if(d < 0)
		{
			d = -d;
			x = -x;
		}

		unordered_map<ll, vector<pair<ll, ll> > > mp;

		for(ll k = 0; k <= n; k++)
		{
			ll modd = ((k*x)%d>=0 ? (k*x)%d : (-(k*x)%d)+d);
			ll kxmod=( x<0 ? (k*x)/d -1 : (k*x)/d );
			// cout << (k*x)/d << ' ' << (k*x)/d -1 << endl;

			mp[modd].EB(kxmod+(((k-1)*k)/2), kxmod+(((2*n-k-1)*k)/2));
		}

		ll ans = 0;

		for(auto i : mp)
		{
			auto j = i.S;

			sort(all(j));

			ll right = -1000000000000000037;
	        for(auto pe: j){
	            ll le=pe.first;
	            ll ri=pe.second;
	            if(ri<=right) 
	            	continue;
	            if(le>right)
	            {
	                ans+=ri-le+1;
	            }
	            else
	            {
	                ans+=ri-right;
	            }
	            right=ri;
	        }

		}
		cout << ans << '\n';
	}
		

	

	return 0;
}
