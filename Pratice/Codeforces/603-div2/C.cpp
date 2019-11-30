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

		set<int> ss;
		ss.emplace(0);

		for(int i = 1; i*i <= n; i++)
		{
			ss.emplace(i);
			ss.emplace(n/i);
		}

		printf("%d\n", ss.size());

		for(auto i : ss)
			printf("%d ", i);
		printf("\n");
	}

	return 0;
}