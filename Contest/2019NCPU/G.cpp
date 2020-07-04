#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = (y); x <= (z); x++)
#define REPP(x, y, z) for(int x = (y); x >= (z); x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn 20
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int cases, n, m;
int x, y, cnt;
vector<int> g[maxn];
vector<PII> edges;
vector<int> e[maxn];
bool vis[maxn];
//functions

void dfs(int n)
{
    vis[n] = true;

    for(auto i : g[n])
        if(!vis[i])
            dfs(i);
}

void dfs2(int n)
{
    vis[n] = true;

    for(auto i : e[n])
        if(!vis[i])
            dfs(i);
        else
           cnt++; 
}

bool connected(void){
    MSET(vis, false);
    
    dfs(1);

    bool flag = true;

    REP(i, 1, n)
        if(!vis[i]){
            flag = false;
            break;
        }

    if(flag)
        return true;
    else
        return false;
}

bool cycle(void){
    for(int i = 0; i < 1<<m; i++){
        for(int j = 0; j <= n; j++)
			e[j].clear();

        int st = 0;

        for(int j = 0; j <= m; j++){
            if(m&&1<<j){
                e[edges[j].F].EB(edges[j].S);
                e[edges[j].S].EB(edges[j].F);
                st = edges[j].F;
            }
        }

        MSET(vis, false);
        cnt = 0;

        dfs2(st);

        if(cnt > 2)
            break;
    }

    if(cnt > 2)
        return true;
    else
        return false;
}


int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

	cin >> cases;

    while(cases--){

        for(int i = 0; i < maxn; i++)
            g[i].clear();
        edges.clear();

        cin >> n >> m;

        REP(i, 1, m){
            cin >> x >> y;
            g[x].EB(y);
            g[y].EB(x);
            edges.EB(MP(x, y));
        }

        if(!connected() || m <= n)
            cout << "n\n";
        else if(cycle() || m > n+1)
            cout << "y: there are at least three cycles\n";
        else
            cout << "y\n";
    }

	return 0;
}