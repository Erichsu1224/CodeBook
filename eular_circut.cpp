#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= z; x++)
#define maxn 50000+5
#define maxm 200000+5
  
//structure
  
//declaration
int n, m;
int st;
vector<PII> adj[maxn];
vector<bool> edges;
int chk[maxn];
//functions
  
  
void dfs(int v)
{
    for(auto i : adj[v])
    {
        if(edges[i.first] == true)
        {
            edges[i.first] = false;
            dfs(i.second);
            cout << i.second << ' ' << v << '\n';
        }
    }
}
  
int main(void)
{
    //IOS;
  
    while(cin >> n >> m)
    {
  
        //init
        REP(i, 1, n)
            adj[i].clear();
        edges.clear();
        memset(chk, 0, sizeof(chk));
          
        int x, y;
  
        REP(i, 1, m)
        {
            cin >> x >> y;
            edges.PB(true);
            adj[x].PB(MP(i-1, y));
            adj[y].PB(MP(i-1, x));
            chk[x]++;
            chk[y]++;
        }
  
        //find 奇數點
        st = 1;
        REP(i, 1, n)
        {
            if(chk[i]%2 == 1)
            {
                st = i;
                break;
            }
        }
  
        dfs(st);
    }
  
    return 0;
}

