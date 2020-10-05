int n, m, Left[maxn], G[maxn][maxn];
bitset<maxn> used;

bool dfs(int s)
{
    for (int i = 1; i <= m; i++)
    {
        if (!G[s][i] || used[i])
        {
            continue;
        }
        used[i] = true;
        if (Left[i] == -1 || dfs(Left[i]))
        {
            Left[i] = s;
            return true;
        }
    }
    return false;
}

int sol()
{
    int ret = 0;
    memset(Left, -1, sizeof(Left));
    for (int i = 1; i <= n; i++)
    {
        used.reset();
        if (dfs(i))
        {
            ret++;
        }
    }
    return ret;
}