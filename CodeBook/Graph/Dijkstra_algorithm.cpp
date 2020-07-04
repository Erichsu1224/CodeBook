#define MP make_pair
#define PII pair<int, int>
#define maxn

int dis[maxn];
vector<PII> e[maxn];

void dijk(int cur)
{ 
  int d;
  priority_queue<PII,vector<PII>,greater<PII>> q;
  q.push( MP(0, cur) );
    
  while (!q.empty()) 
  {
    tie(d, cur) = q.top();
    q.pop();
    if (dis[cur] != 1e9) 
        continue;

    dis[cur] = d;

    for (auto i: e[cur])
        if (dis[i.first] == 1e9) 
        {
            q.push( MP(d+i.second, i.first) );
        }
    }
}

void init(void)
{
    fill(dis, dis+maxn, 1e9);

    for(int i = 0; i < maxn; i++)
    {
        e[i].clear();
    }
}