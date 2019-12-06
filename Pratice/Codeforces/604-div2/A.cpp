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
char list[] = "abc";
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int T;
	string str;
	scanf("%d", &T);

	while(T--)
	{
		cin >> str;
		bool flag = true;

		for(int i = 0; i < str.size(); i++)
		{
			if(i && str[i] == str[i-1] && str[i] != '?')
			{
				// cout << i << ' ';
				flag = false;
				break;
			}

			if(!i && str[i] == '?')
			{
				str[i] = (str[i+1]-'a'+1)%3+'a';
			}

			if(str[i+1] == '?')
			{
				str[i+1] = (str[i]-'a'+1)%3+'a';

				if(str[i+2] == str[i+1])
				{
					str[i+1] = (str[i+1]-'a'+1)%3+'a';
				}
			}
		}

		if(!flag)
			printf("-1\n");
		else
			cout << str << '\n';
	}

	return 0;
}