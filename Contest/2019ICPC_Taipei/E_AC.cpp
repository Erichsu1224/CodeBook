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
int T, k, m;
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
		scanf("%d %d", &k, &m);

		if(m >= 2000)
		{
			printf("-1\n");
			continue;
		}

		// 1999
		printf("1999\n");

		for(int i = 1; i <= 1997; i++)
		{
			printf("0 ");
		}

		ll tmp = 1998 - (k%1998);

		printf("%d ", -tmp);
		printf("%d\n", (1999*tmp+k)/1998);

		
	}

	return 0;
}