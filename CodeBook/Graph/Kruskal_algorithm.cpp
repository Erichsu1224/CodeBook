#define maxn 

template <typename T>
struct Kruskal{

	struct Edge
	{
		int from, to;
		T cost;

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

	int par[maxn];
	int n, m;
	T cost;
	vector<Edge> edges;

	int find(int x){ 
		return par[x] < 0 ? x : (par[x] = find(par[x]));
	}

	void conn(int x,int y){
		int xx = find(x);
		int yy = find(y);

		if(xx == yy)
			return;

		par[xx] += par[yy];
		par[yy] = xx;
	}

	void add_Edge(int from, int to, T w){
		edges.emplace_back((Edge){from, to, w});
	}

	T kruskal_algorithm(void)
	{
		cost = 0;
		memset(par, -1, sizeof(par));
		sort(edges.begin(), edges.end());

		for(int i = 0; i < m; i++)
		{
			Edge tmp = edges[i];

			if(find(tmp.to) == find(tmp.from))
			{
				//不能形成環的邊
				continue;
			}

			else
			{
				cost += tmp.cost;
				conn(tmp.from, tmp.to);
				
			}
		}

		return cost;
	}
};