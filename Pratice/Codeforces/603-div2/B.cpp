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
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &n);

		map<string, int> mp;
		vector<string> v;

		string str;
		int ans = 0;

		REP(i, 1, n)
		{
			cin >> str;

			mp[str]++;

			v.EB(str);
		}

		REP(l, 0, n-1)
		{
			if(mp[v[l]] > 1)
			{
				ans++;
				mp[v[l]]--;

				string tmp = v[l];
				bool flag = false;

				for(int j = 0; j < 4; j++)
				{
					for(char i = '0'; i <= '9'; i++)
					{
						tmp[j] = i;

						if(!mp[tmp])
						{
							mp[tmp] = 1;
							flag = true;
							break;
						}
					}
					if(flag)
						break;
				}
					

				v[l] = tmp;
			}
		}

		printf("%d\n", ans);
		REP(i, 0, n-1)
		{
			cout << v[i] << '\n';
		}
	}

	return 0;
}