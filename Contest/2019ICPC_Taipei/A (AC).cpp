#include <bits/stdc++.h>
using namespace std;

#define ARII array<array<int, 10>, 10>

int main(void)
{
	ARII puz;
	bool flag = false;
	for(int i = 1; i <= 6; i++)
		for(int j = 1; j <= 6; j++)
			scanf("%d", &puz[i][j]);

	queue<pair<ARII, int> > q;
	set<ARII> his;

	q.push(make_pair(puz, 0));
	his.insert(puz);

	while(!q.empty())
	{
		ARII now;	int step;

		tie(now, step) = q.front();	q.pop();

		//find red car
		if(now[3][6] == 1)
		{
			printf("%d\n", step+2);
			flag = true;
			break;
		}

		if(step == 8)
			continue;

		ARII tmp;

		set<int> vis;

		for(int i = 1; i <= 6; i++)
			for(int j = 1; j <= 6; j++)
			{
				if(vis.count(now[i][j]))
					continue;
				vis.insert(now[i][j]);

				if(i < 6)
				{
					if(now[i][j] == now[i+1][j])
					{
						if(i < 5 && now[i+1][j] == now[i+2][j])
						{
							if(i+3 <= 6 && now[i+3][j] == 0)
							{
								tmp = now;
								tmp[i+3][j] = tmp[i][j];
								tmp[i][j] = 0;
								if(!his.count(tmp))
									q.push(make_pair(tmp, step+1));
							}

							if(i-1 >= 1 && now[i-1][j] == 0)
							{
								tmp = now;
								tmp[i-1][j] = tmp[i][j];
								tmp[i+2][j] = 0;
								if(!his.count(tmp))
									q.push(make_pair(tmp, step+1));
							}
						}

						else
						{
							if(i+2 <= 6 && now[i+2][j] == 0)
							{
								tmp = now;
								tmp[i+2][j] = tmp[i][j];
								tmp[i][j] = 0;
								if(!his.count(tmp))
									q.push(make_pair(tmp, step+1));
							}

							if(i-1 >= 1 && now[i-1][j] == 0)
							{
								tmp = now;
								tmp[i-1][j] = tmp[i][j];
								tmp[i+1][j] = 0;
								if(!his.count(tmp))
									q.push(make_pair(tmp, step+1));
							}
						}
					}
				}

				if(j < 6)
				{
					if(now[i][j] == now[i][j+1])
					{
						if(j+2 <= 6 && now[i][j] == now[i][j+2])
						{
							if(j+3 <= 6 && now[i][j+3] == 0)
							{
								tmp = now;
								tmp[i][j+3] = tmp[i][j];
								tmp[i][j] = 0;

								if(!his.count(tmp))
									q.push(make_pair(tmp, step+1));
							}


							if(j-1 >= 1 && now[i][j-1] == 0)
							{
								tmp = now;
								tmp[i][j-1] = tmp[i][j];
								tmp[i][j+2] = 0;
								if(!his.count(tmp))
									q.push(make_pair(tmp, step+1));
							}
						}

						else
						{
							if(j+2 <= 6 && now[i][j+2] == 0)
							{
								tmp = now;
								tmp[i][j+2] = tmp[i][j];
								tmp[i][j] = 0;

								if(!his.count(tmp))
									q.push(make_pair(tmp, step+1));
							}


							if(j-1 >= 1 && now[i][j-1] == 0)
							{
								tmp = now;
								tmp[i][j-1] = tmp[i][j];
								tmp[i][j+1] = 0;
								if(!his.count(tmp))
									q.push(make_pair(tmp, step+1));
							}
						}
					}
				}
			}
	}

	if(!flag)
	{
		printf("-1\n");
	}
}