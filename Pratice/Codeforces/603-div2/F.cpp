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
#define maxn 2010

//structure

//declaration
vector<int> v[maxn];
int n, m;
int leaf[maxn], sz[maxn], dp[maxn];
vector<PII> ranges[maxn];
//functions

PII dfs(int now)
{
	if(now != 1)
		sz[now] = 1;
	else
		sz[now] = 0;

	int minn = 1e9, maxx = 0;
	if(leaf[now])
	{
		minn = maxx = leaf[now]; //main grid's range
	}

	for(auto i : v[now])
	{
		PII tmp = dfs(i);
		sz[now] += sz[i];
		minn = min(minn, tmp.F);
		maxx = max(maxx, tmp.S);
	}
	ranges[maxx].EB(MP(minn, sz[now]));
	return MP(minn, maxx);
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	scanf("%d", &n);

	REP(i, 1, 2)
	{	
		REP(j, 1, m)
			v[j].clear();
		MSET(leaf, 0);

		scanf("%d", &m);
		int tmp;

		REP(j, 2, m)
		{
			scanf("%d", &tmp);
			v[tmp].EB(j);
		}

		REP(j, 1, n)
		{
			scanf("%d", &tmp);
			leaf[tmp] = j;
		}

		dfs(1);	

		// //test
		// for(int i = 1; i <= 5; i++)
		// {
		// 	cout << i << ":\n";
		// 	for(auto j : ranges[i])
		// 	{
		// 		cout << j.first << ' ' << j.second << endl;
		// 	}
		// 	cout << endl;
		// }

		
	}

	MSET(dp, 0);

	REP(i, 1, n)
		for(auto j : ranges[i])
			dp[i] = max(dp[i], dp[j.F-1]+j.S);

	printf("%d\n", dp[n]);

	return 0;
}