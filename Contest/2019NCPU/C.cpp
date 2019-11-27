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
int n, m;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(~scanf("%d %d", &n, &m))
	{
		list<int> ls;
		int type;
		int rev = 0;

		REP(i, 1, n)
			ls.PB(i);

		REP(i, 1, m)
		{
			scanf("%d", &type);
			int x, y;

			if(type == 1)
			{
				scanf("%d %d", &x, &y);

				ls.remove(x);


				for(list<int>::iterator it = ls.begin(); it != ls.end(); it++)
				{
					if(*it == y)
					{
						ls.insert(it,x);
						break;
					}
				}
			}

			else if(type == 2)
			{
				scanf("%d %d", &x, &y);

				ls.remove(x);

				bool flag = false;
				for(list<int>::iterator it = ls.begin(); it != ls.end(); it++)
				{
					if(flag)
					{
						ls.insert(it,x);
						flag = false;
						break;
					}
					if(*it == y)
					{
						flag = true;
					}
				}

				if(flag)
					ls.PB(x);
				
					
			}
			else if(type == 3)
			{
				scanf("%d %d", &x, &y);	

				bool flag = true;
				for(list<int>::iterator it = ls.begin(); it != ls.end(); it++)
				{
					if(*it == x)
					{
						ls.insert(it, y);
						ls.erase(it);
					}

					if(*it == y)
					{
						ls.insert(it, x);
						ls.erase(it);
					}
				}
			}
			else if(type == 4)
			{
				rev++;
			}
		}

		ll ans = 0;
		int cnt = 1;

		if(rev%2 == 0)
		{
			for(list<int>::iterator it = ls.begin(); it != ls.end(); it++)
			{
				if(cnt%2 == 1)
				{
					ans += *it;
				}
				cnt++;
			}
		}

		if(rev%2 == 1)
		{
			for(list<int>::iterator it = ls.begin(); it != ls.end(); it++)
			{
				if(cnt%2 == 0)
				{
					ans += *it;
				}
				cnt++;
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}