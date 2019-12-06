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
int T, n;
vector<PII> v;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &n);

		int tmp;
		v.clear();

		REP(i, 1, n)
		{
			scanf("%d", &tmp);
			v.EB(MP(tmp, i));
		}

		sort(all(v));

		int maxx = 0, minn = 1e9;

		REP(i, 0, n-1)
		{
			maxx = max(maxx, v[i].S);
			minn = min(minn, v[i].S);

			if(maxx-minn+1 == i+1)
				printf("1");
			else
				printf("0");
		}

		printf("\n");
	}

	return 0;
}