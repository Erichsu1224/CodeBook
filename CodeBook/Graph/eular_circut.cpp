#define ll long long
#define PB push_back
#define EB emplace_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define maxn 50000+5
  
//structure
struct Eular{
    vector<PII> adj[maxn];
    vector<bool> edges;
    vector<PII> path;
    int chk[maxn];
    int n;

    void init(int _n){
        n = _n;

        for(int i = 0; i <= n; i++)
            adj[i].clear();
        edges.clear();
        path.clear();
        memset(chk, 0, sizeof(chk));
    }

    void dfs(int v)
    {
        for(auto i : adj[v])
        {
            if(edges[i.first] == true)
            {
                edges[i.first] = false;
                dfs(i.second);
                path.EB(MP(i.second, v));
            }
        }
    }

    void add_Edge(int from, int to){
        edges.PB(true);

        // for bi-directed graph
        adj[from].PB(MP(edges.size()-1, to));
        adj[to].PB(MP(edges.size()-1, from));
        chk[from]++;
        chk[to]++;

        // for directed graph
        // adj[from].PB(MP(edges.size()-1, to));
        // check[from]++;
    }

    bool eular_path(){
        int st = -1;
        for(int i = 1; i <= n; i++){
            if(chk[i]%2 == 1){
                st = i;
                break;
            }
        }

        if(st == -1){
            return false;
        }

        dfs(st);

        return true;
    }

    void print_path(void){
        for(auto i : path){
            printf("%d %d\n", i.first, i.second);
        }
    }
};