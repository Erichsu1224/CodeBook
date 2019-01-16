//dijkstra
//最短路徑

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
