#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define PB push_back
#define PII par<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define MSET() memset(x, y, sizeof(x))
#define F first
#define S second
#define maxn

int n;
int cnt[maxn];
vector<int> g[maxn];
int node[maxn];
bool vis[maxn];


void dfs(int now, int fa)
{
    if(!vis[now])
    {
        if(cnt[now] == node[now]-1)
        {

        }
    }
}

int main(){

    while(~scanf("%d", &n))
    {
        //init
        for(int i = 0; i <= n; i++)
            g[i].clear();
        MSET(vis, false)



        int x, y;
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &x, &y);

            node[x]++;
            node[y]++;
            g[x].PB(y);
            g[y].PB(x);
        }

        for(int i = 1; i <= n; i++)
        {
            node[i] = true;
        }
    }

    return 0;
}
