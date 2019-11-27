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
#define maxn

//structure

//declaration
int T;
ll n;
ll arr[15];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	scanf("%d", &T);

	REP(i, 1, 12)
	{
		ll tmp = 1;

		REP(j, 1, i)
		{
			tmp *= j;
		}

		arr[i] = tmp;
		cout << tmp << endl;
	}
	while(T--)
	{
		scanf("%lld", &n);

		ll ans;

		REP(i, 1, 12)
		{
			if(arr[i]%n == 0)
			{
				ans = i;
				break;
			}	
		}
		printf("%d\n", ans);
	}

	return 0;
}