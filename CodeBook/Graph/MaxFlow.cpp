struct Edge{
    int t,r,opp,next; // t=邊的終點，r=剩餘流量, opp=反向邊編號, next=下一條邊編號(鍊表)
    Edge () {}
    Edge (int a,int b,int c,int d) { t=a; r=b; opp=c; next=d; }
}in[M*25];
int e,st,ed; // 當前邊標號, 源點, 匯點
int first[M],arc[M],dis[M]; // arc: bfs完以後，每個點找剩餘流找到哪條邊的標記
void add(int x,int y,int z) { // 加一條 x->y， 流量 z 的邊
    in[e] = Edge(y,z,e+1,first[x]);
    first[x] = e++;
    in[e] = Edge(x,0,e-1,first[y]);
    first[y] = e++;
}
void init() {
    e = 0;
    MSET(first, -1);
    MSET(dis, 0);
}
bool bfs() {
    int cur;
    queue<int> q;
    REP(i,0,n) dis[i] = 0;
    REP(i,0,n) arc[i] = first[i];
    dis[ed] = 1;
    q.push(ed);

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i=first[cur]; ~i; i=in[i].next)
            if (in[in[i].opp].r && !dis[in[i].t]) {
                dis[in[i].t] = dis[cur] + 1;
                q.push(in[i].t);
            }
    }
    return dis[st] > 0;
}
int dfs(int cur,int flow) {
    if (cur==ed) return flow;
    int re=0, tmp;
    for (int i=arc[cur]; ~i; i=arc[cur]=in[i].next)
        if (dis[in[i].t]==dis[cur]-1 && in[i].r>0) { //如果距離編號剛好小1，且有剩餘流量
            tmp = dfs(in[i].t, min(in[i].r, flow));
            re += tmp;
            flow -= tmp;
            in[i].r -= tmp;
            in[in[i].opp].r += tmp;
            if (!flow) return re;
        }
    return re;
}
int maxflow() {
    int res = 0;
    while(bfs()) res += dfs(st, 2000000000);
    return res;
}