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
struct Item
{
	string MAC;
	int RSSI, stamp;

	bool operator< (const Item& rs)const
	{
		if(RSSI == rs.RSSI)
			return MAC < rs.MAC;
		return RSSI > rs.RSSI;
	}
};
//declaration
int T, n;
vector<Item> v;
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
		v.clear();
		scanf("%d", &n);

		string x;
		int y, z;

		REP(i, 1, n)
		{
			cin >> x;
			scanf("%d %d", &y, &z);

			if(z >= 1000)	continue;

			v.PB((Item){x, y, z});
		}

		sort(all(v));

		REP(i, 0, v.size()-1)
		{
			if(i > 2)
				break;
			cout << v[i].MAC;
			printf(" %d\n", v[i].RSSI);
		}
	}

	return 0;
}