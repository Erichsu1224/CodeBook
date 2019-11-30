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
//functions

int main(void)
{
	
	scanf("%d", &n);
	
	{
		REP(i, 1, n)
		{
			ll a, b, c;

			scanf("%lld %lld %lld", &a, &b, &c);

			printf("%d\n", min(min(min(a+b, b+c), a+c), (a+b+c)/2));
		}
	}

	return 0;
}