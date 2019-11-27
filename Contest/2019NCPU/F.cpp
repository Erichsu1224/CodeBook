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
int T;
stack<char> st;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	scanf("%d\n", &T);

	while(T--)
	{
		string tmp;
		cin >> tmp;
		
		for(int i = 0; i < tmp.size(); i++)
		{
			if(tmp[i] == ']')
			{
				string hold = "";
				while(!st.empty())
				{
					char tt = st.top();	st.pop();

					if(tt == '[')
					{
						int num = st.top()-'0';	st.pop();
						
						REP(i, 1, num)
						{
							REPP(j, hold.size()-1, 0)
							{
								st.push(hold[j]);
							}
						}
						break;
					}	

					else
					{
						hold += tt;
					}
					
				}
			}

			else
			{
				st.push(tmp[i]);
			}
		}

		string hold = "";

		while(!st.empty())
		{
			hold += st.top(); st.pop();
		}

		REPP(i, hold.size()-1, 0)
			cout << hold[i];
		puts("");
	}

	return 0;
}