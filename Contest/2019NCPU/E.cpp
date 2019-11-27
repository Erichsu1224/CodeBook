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
int n;
int dp[25][25][25];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	MSET(dp, 0);

	dp[0][1][1] = 1;

	REP(i, 1, 20)
	{
		REP(j, 1, i+1)
		{
			REP(k, 1, j)
			{
				dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k] + dp[i-1][j-1][k-1];
			}
		}
	}

	while(~scanf("%d", &n))
	{
		REP(i, 1, n+1)
		{
			REP(j, 1, i)
			{
				if(j == 1)
					printf("%d", dp[n][i][j]);
				else
				{
					printf(" %d", dp[n][i][j]);
				}
				
			}
			puts("");
		}
	}
	return 0;
}