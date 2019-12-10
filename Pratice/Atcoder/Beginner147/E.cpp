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
#define maxn 80+5

//structure

//declaration
int a[maxn][maxn];
int b[maxn][maxn];
bool dp[maxn][maxn][6400*2+10];
//functions


int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int h, w;
	MSET(dp, false);

	scanf("%d %d", &h, &w);

	REP(i, 1, h)
		REP(j, 1, w)
			scanf("%d", &a[i][j]);
	
	REP(i, 1, h)
		REP(j, 1, w)
			scanf("%d", &b[i][j]);

	dp[1][1][6400-abs(a[1][1]-b[1][1])] = true;
	dp[1][1][6400+abs(a[1][1]-b[1][1])] = true;

	REP(i, 1, h)
		REP(j, 1, w)
		{
			REP(k, 1, 6400*2+5)
			{
				if(dp[i][j][k])
				{
					// cout << i << ' ' << j << ' ' << k << endl;
					if(i+1 <= h)
					{
						dp[i+1][j][k+abs(a[i+1][j]-b[i+1][j])] = true;
						dp[i+1][j][k-abs(a[i+1][j]-b[i+1][j])] = true;
					}
					
					if(j+1 <= w)
					{
						dp[i][j+1][k+abs(a[i][j+1]-b[i][j+1])] = true;
						dp[i][j+1][k-abs(a[i][j+1]-b[i][j+1])] = true;
					}	
				}
			}
		}

	int ans = 1e9;

	REP(i, 0, 6400*2+5)
	{
		if(dp[h][w][i] == true)
		{
			// cout << i << ' ' << ans << endl;
			ans = min(ans, abs(i-6400));
		}
	}

	printf("%d\n", ans);
	return 0;
}