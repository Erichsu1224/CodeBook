dynamic programing

LIS
int main(int argc, char const *argv[])
{
    int ls[100050];
    int dp[100050];
    int x;
 
    cin >> x;
 
    for(int i = 0; i < x; i++)
    {
        cin >> ls[i];
    }
 
    memset(dp, 0, x+5);
    dp[0] = ls[0];
    int top = 0;
 
    for(int i = 1; i < x; i++)
    {   
        int left = 0, right = top;
		bool found = false;

		while(left <= right)
		{
			if(ls[i] > dp[(left+right)/2])	left = (left+right)/2+1;
			else if(ls[i] < dp[(left+right)/2])		right = (left+right)/2-1;
			else if(ls[i] == dp[(left+right)/2])	
			{
				found = true;
				break;
			}
		}
		if(found)	continue;
		dp[right+1] = ls[i];

		if(right == top)	top++;
    }

    //test
    for(int i = 0; i < x; i++)
    {
    	printf("%d ", dp[i]);
    }
    cout << endl;
 
    cout << top+1 << endl;
    return 0;
}

LCS
#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    if(a >= b) return a;
    else return b;
}

int main(int argc, char const *argv[])
{
    int n, m;
    vector <int> lis1;
    vector <int> lis2;
    lis1.push_back(0);
    lis2.push_back(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int hold;

        cin >> hold;

        lis1.push_back(hold);
    }

    for(int i = 0; i < m; i++)
    {
        int hold;
        cin >> hold;

        lis2.push_back(hold);
    }

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= m; k++)
        {
            if(lis1[i] == lis2[k])
            {
                dp[i][k] = dp[i-1][k-1] + 1;
            }

            else
            {
                dp[i][k] = max(dp[i][k-1], dp[i-1][k]);
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}

big number

graph
dijkstra

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
 
#define maxn 51415

struct Edge
{
	int from, to, dist;

	Edge(int _from, int _to, int _dist)
    {
        from = _from;
        to = _to;
        dist = _dist;
    }
};
 
struct Item
{
    int node;
    int dist;
 
    Item(int _node, int _dist)
    {
        node = _node;
        dist = _dist;
    }
 
    bool operator <(const Item& rs) const
    {
        return dist > rs.dist;
    }
};
 
int main(void)
{
    int n, m;
    while(scanf("%d %d", &n, &m))
    {
    	vector <Edge> edges;
    	vector<int> G[maxn]; 
        priority_queue <Item> dij;
 
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            edges.push_back(Edge(a, b, c));
            G[a].push_back(i);
        }

        int node = 1;
        dij.push(Item(1, 0));
        Item hold = Item(0, 0);
        while(!dij.empty())
        {
            hold = dij.top(); 
            dij.pop();
            node = hold.node;
            if(node == n)
            {
                break;
            }
 
            for(int i = 0; i < G[node].size(); i++)
            {
               dij.push(Item(edges[G[node][i]].to, hold.dist+edges[G[node][i]].dist));
            }
        }

        if(node != n) printf("-1\n");
        if(node == n)  printf("%d\n", hold.dist);
    }
    return 0;
}

kruskal algorithm
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define maxn 10000

int graph[maxn];
int parent_arr[maxn];

struct Edge
{
	int from, to, cost;

	Edge(int _from, int _to, int _cost) 
	{
		from = _from;
		to = _to;
		cost = _cost;
	}

	bool operator< (const Edge &r) const
	{
		return r.cost < cost;
	}
};

int main(void)
{
	int cases;
	while(cin >> cases)
	{
		if(cases == 0)
			break;
		while(cases--)
		{
			int n, m;
			int cost = 0;
			vector<Edge> edges;
			cin >> n >> m;

			for(int i = 0; i < m; i++)
			{
				int a, b, c;
				cin >> a >> b >> c;
				edges.push_back(Edge(a, b, c));
			}

			sort(edges.begin(), edges.end());

			memset(parent_arr, -1, sizeof(parent_arr));

			for(int i = 0; i < m; i++)
			{
				if(parent_arr[edges[i].to] != -1)
				{
					cost += edges[i].cost;
					continue;
				}

				else if(parent_arr[edges[i].to] == -1)
				{
					parent_arr[edges[i].to] = edges[i].from;
					while(parent_arr[parent_arr[edges[i].to]] >= 0)
					{
						parent_arr[edges[i].to] = parent_arr[parent_arr[edges[i].to]];
					}
					parent_arr[parent_arr[edges[i].to]]--;
				}
			}

			cout << cost << endl;
		}
	}
	return 0;
}