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
#define maxn 2000+5

//structure

//declaration
ll dp[maxn][maxn];
ll ques[maxn];

ll mod = 998244353;

//functions

ll poww(ll a, ll b)
{
	ll tmp = 1;
	while(b)
	{
		if(b&1)
			tmp = (tmp*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return tmp;
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	string str;
	cin >> str;

	str = " " + str;

	int n = str.size()-1;

	REP(i, 1, n)
	{
		ques[i] = ques[i-1]+(str[i]=='?');
	}

	REP(len, 2, n)
	{
		for(int i = 1; i+len-1 <= n; i++)
		{
			int j = i+len-1;

			if(str[i] != '(')
				dp[i][j] = (dp[i][j] + dp[i+1][j])%mod;
			if(str[j] != ')')
				dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
			if(str[i] != '(' && str[j] != ')')
				dp[i][j] = (dp[i][j] - dp[i+1][j-1] +mod )%mod;
			if(str[i] != ')' && str[j] != '(')	// Means that either one side is '?'
			{
				dp[i][j] = ((dp[i][j] + dp[i+1][j-1])%mod + poww(2, ques[j-1]-ques[i]))%mod;
			}
		}
	}

	cout << dp[1][n] << '\n';


	return 0;
}
