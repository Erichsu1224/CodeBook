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
#define maxn 1000000+10

//structure

//declaration
int n;
int p;
char str[maxn];
int sum[maxn<<2], ma[maxn<<2], mi[maxn<<2];
//functions
void update(int now, int l, int r, int pos, int c)
{
	if(l == r)
	{
		sum[now] = ma[now] = mi[now] = c;
		return; 
	}

	int mid = (l+r)/2;
	if(pos <= mid)
		update(now<<1, l, mid, pos, c);
	else
		update(now<<1|1, mid+1, r, pos, c);
	sum[now] = sum[now<<1]+sum[now<<1|1];
	ma[now] = max(ma[now<<1], sum[now<<1]+ma[now<<1|1]);
	mi[now] = min(mi[now<<1], sum[now<<1]+mi[now<<1|1]); 
}

int main(void)
{
	scanf("%d\n", &n);
	p = 1;
	scanf("%s", str);

	REP(i, 0, n-1)
	{
		if(str[i] == 'L')
		{
			if(p > 1)
				p--;
		}

		else if(str[i] == 'R')
		{
			p++;
		}

		else
		{
			if(str[i] == '(')
				update(1, 1, n, p, 1);
			else if(str[i] == ')')
				update(1, 1, n, p, -1);
			else
				update(1, 1, n, p, 0);
		}

		if( mi[1]==0 && sum[1]==0 ) printf("%d ",ma[1]);
		else printf("-1 ");

		// //test
		// cout << endl;
		// REP(i, 1, 4*n)
		// 	cout << sum[i] << ' ';
		// cout << endl;
		// REP(i, 1, 4*n)
		// 	cout << ma[i] << ' ';
		// cout << endl;
		// REP(i, 1, 4*n)
		// 	cout << mi[i] << ' ';
		// cout << endl;
	}

	return 0;
}