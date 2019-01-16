//kruskal algorithm
//minimum spanning tree

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define maxn 10100

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
		return cost < r.cost;
	}
};

int graph[maxn];
int parent_arr[maxn];
int n, m;
vector<Edge> edges;

int find(int x)
{ 
	return parent_arr[x] < 0 ? x : (parent_arr[x] = find(parent_arr[x]));
}

void kruskal_algorithm(int vertex, int edge)
{
	int cost = 0;
	memset(parent_arr, -1, sizeof(parent_arr));
	sort(edges.begin(), edges.end());

	for(int i = 0; i < edge; i++)
	{
		Edge tmp = edges[i];

		if(find(tmp.to) == find(tmp.from) && parent_arr[tmp.to] != -1)
		{
			//不能形成環的邊
			continue;
		}

		else
		{
			if(parent_arr[tmp.to] == -1)
			{
				parent_arr[find(tmp.from)] += -1;
				parent_arr[tmp.to] = tmp.from;
			}

			else if(parent_arr[tmp.from] == -1)
			{
				parent_arr[find(tmp.from)] -= 1;
				parent_arr[tmp.from] = tmp.to;
			}
			else
			{
				parent_arr[find(tmp.to)] += parent_arr[find(tmp.from)];
				parent_arr[find(tmp.from)] = find(tmp.to);
			}
		}
	}
}

int main(void)
{
	while(scanf("%d %d", &n, &m))
	{
		for(int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			edges.push_back(Edge(a, b, c));

			kruskal_algorithm();

			edges.clear();	
		}
	}
	return 0;
}
