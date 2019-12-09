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
#define maxn 20

//structure

//declaration
vector<PII> v[maxn];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n, m;

	scanf("%d", &n);

	REP(i, 1, n)
	{
		scanf("%d", &m);

		int x, y;

		REP(j, 1, m)
		{
			scanf("%d %d", &x, &y);

			v[i].PB(MP(x, y));
		}
	}

	int check[maxn], ans = 0;

	MSET(check, -1);

	for(int i = 0; i < (1 << n); i++)
	{
		bitset<15> b(i);

		REP(j, 0, n-1)
		{
			if(b[j] == 1)
				check[j+1] = 1;
			else
				check[j+1] = 0;
		}

		bool flag = true;

		REP(j, 1, n)
		{
			for(auto k : v[j])
			{
				if(check[j] == 1)
				{
					if(check[k.F] != k.S)
					{
						flag = false;
						break;
					}
				}
			}

			if(!flag)
				break;
		}

		if(flag)
			ans = max(ans, (int)b.count());
	}

	printf("%d\n", ans);

	return 0;
}