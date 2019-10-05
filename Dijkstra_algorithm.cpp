//dijkstra
#include <bits/stdc++.h>
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

int n, m;
vector <Edge> edges;
vector<int> G[maxn]; 
bool visit[maxn];
int start, node;
 
int main(void)
{
    while(cin >> n >> m)
    {
    	//init
        priority_queue <Item> dij;
        edges.clear();
        for(int i = 0; i <= n; i++)
        {
            G[i].clear();
        }
        memset(visit, false, sizeof(visit));

 
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            edges.push_back(Edge(a, b, c));
            G[a].push_back(i);
        }

        // start vertex
        start = 1;
        node = 0;
        
        dij.push(Item(start, 0));
        Item hold = Item(0, 0);
        while(!dij.empty())
        {
            hold = dij.top(); 
            dij.pop();
            cout << hold.node << ' ' << hold.dist << endl;

            if(visit[hold.node] == true)
                continue;

            visit[hold.node] = true;

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
