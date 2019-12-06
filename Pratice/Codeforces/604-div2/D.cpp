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

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int arr[4];

	scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);

	int total = arr[0]+arr[1]+arr[2]+arr[3]-1;

	deque<int> dq;

	int tmp = -1;
	int maxx = 0;

	for(int i = 0; i < 4; i++)
	{
		if(arr[i] > maxx)
		{
			tmp = i;
			maxx = arr[i];
		}
	}

	if(tmp == -1)
	{
		printf("NO\n");
		return 0;
	}

	arr[tmp]--;
	dq.PB(tmp);

	bool flag = true;

	while(total--)
	{
		int fr = dq.front(), ba = dq.back();

		// cout << fr << ' ' << ba << endl;
		// printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);

		if(ba > 0 && arr[ba-1] > 0)
		{
			dq.PB(ba-1);
			arr[ba-1]--;
			continue;
		}

		if(ba < 3 && arr[ba+1] > 0)
		{
			dq.PB(ba+1);
			arr[ba+1]--;
			continue;
		}

		if(fr > 0 && arr[fr-1] > 0)
		{
			dq.push_front(fr-1);
			arr[fr-1]--;
			continue;
		}

		if(fr < 3 && arr[fr+1] > 0)
		{
			dq.push_front(fr+1);
			arr[fr+1]--;
			continue;
		}

		flag = false;
		break;
	}

	if(!flag)
		printf("NO\n");
	else
	{
		printf("YES\n");
		int k = 0;
		while(!dq.empty())
		{
			if(k)
				printf(" %d", dq.front());
			else
				printf("%d", dq.front());
			dq.pop_front();
			k++;
		}
		printf("\n");
	}
	return 0;
}