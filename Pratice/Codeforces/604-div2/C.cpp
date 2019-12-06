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

		int tmp, g = 0, s = 0, b = 0, hold, l = 1, flag = 1;

		REP(i, 1, n)
		{
			scanf("%d", &tmp);

			if(i <= n/2+1)
			{
				// cout << l << ' ' <<  i  << endl;
				if(i > 1 && hold != tmp)
				{
					if(flag == 1)
					{
						g += i-l;
						l = i;
						hold = tmp;
						flag++;
						// cout << "Flag:" <<  flag << ' ' << g << endl;
					}

					else if(flag == 2)
					{
						// cout << "Flag:" << flag << endl;
						if(g >= i-l)
						{
							// cout << "2-1" << endl;
							hold = tmp;
						}
						else
						{
							// cout << "2-2" << endl;
							s += i-l;
							l = i;
							hold = tmp;
							flag++;
						}
					}
					else if(flag == 3)
					{
						// cout << "Flag:" <<  flag << endl;
						if(g >= i-l)
						{
							hold = tmp;
						}
						else
						{
							b += i-l;
							l = i;
							hold = tmp;
							flag++;
						}
					}

					else
					{
						b += i-l;
						l = i;
						hold = tmp;
					}

				}

				hold = tmp;
			}
				
		}

		// cout << g << ' ' << s << ' ' << b << endl;

		if(n < 6)
			printf("0 0 0\n");
		else
		{
			if(!g || !s || !b)
				printf("0 0 0\n");
			else
				printf("%d %d %d\n", g, s, b);
		}
	}

	return 0;
}