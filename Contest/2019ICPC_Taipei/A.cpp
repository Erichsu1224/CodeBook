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

int puz[10][10];
int cnt;

void dfs(int now_l, int now_r, int dir_a, int dir_b, int row)
{
    printf("%d %d %d %d %d\n", now_l, now_r, dir_a, dir_b, row);
    if(cnt > 10)
        return;
    if(dir_a == 1)
    {
        if(now_r+dir_b > 6 || now_l+dir_b < 1)
            dir_b = -1;
        if(puz[row][now_r+dir_b] == 0)
        {
            cnt++;
            dfs(now_l+dir_b, now_r+dir_b, dir_a, dir_b, row);
        }

         else
         {
             int id = puz[row][now_r+dir_b];
             if(puz[row][now_r+dir_b+1] == id || puz[row][now_r+dir_b-1] == id)
             {
                 int l, r;
                 for(int i = now_r+dir_b; i >= 1; i--)
                 {
                     if(puz[row][i] == id && puz[row][i-1] != id)
                    {
                        l = i;
                        break;
                    }
                 }

                 for(int i = now_r+dir_b; i <= 6; i++)
                 {
                     if(puz[row][i] == id && puz[row][i+1] != id)
                    {
                        r = i;
                        break;
                    }
                 }

                    cout << 1 << endl;
                 dfs(l, r, 1, 1, row);
             }

             else
             {
                 int l, r;
                 for(int i = row; i >= 1; i--)
                 {
                     if(puz[i][now_r+dir_b] == id && puz[i-1][now_r+dir_b] != id)
                    {
                        l = i;
                        break;
                    }
                 }

                 for(int i = row; i <= 6; i++)
                 {
                     if(puz[i][now_r+dir_b] == id && puz[i+1][now_r+dir_b] != id)
                    {
                        r = i;
                        break;
                    }
                 }
                cout << 2 << endl;
                 dfs(l, r, 0, 1, now_r+dir_b);
             }

         }
    }

    if(dir_a == 0)
    {
        if(now_r+dir_b > 6 || now_l+dir_b < 1)
            dir_b = -1;
        if(puz[now_r+dir_b][row] == 0)
        {
            cnt++;
            dfs(now_l+dir_b, now_r+dir_b, dir_a, dir_b, row);
        }

        else
        {
            int id = puz[now_r+dir_b][row];
             if(puz[now_r+dir_b+1][row] == id || puz[now_r+dir_b+1][row] == id)
             {
                 int l, r;
                 for(int i = now_r+dir_b; i >= 1; i--)
                 {
                    if(puz[i][row] == id && puz[i-1][row] != id)
                    {
                        l = i;
                        break;
                    }
                 }

                 for(int i = now_r+dir_b; i <= 6; i++)
                 {
                    if(puz[i][row] == id && puz[i+1][row] != id)
                    {
                        r = i;
                        break;
                    }
                 }
                    cout << 3 << endl;
                 dfs(l, r, 0, 1, row);
             }

             else
             {
                 int l, r;
                 for(int i = row; i >= 1; i--)
                 {
                     if(puz[now_r+dir_b][i] == id && puz[now_r+dir_b][i-1] != id)
                    {
                        l = i;
                        break;
                    }
                 }

                 for(int i = row; i <= 6; i++)
                 {
                     if(puz[now_r+dir_b][i] == id && puz[now_r+dir_b][i+1] != id)
                    {
                        r = i;
                        break;
                    }
                 }
                    cout << 4 << endl;
                 dfs(l, r, 1, 1, now_r+dir_b);
             }

        }
    }
}

int main()
{
    cnt = 0;
    for(int i = 1; i <= 6; i++)
    {
        for(int j = 1; j <= 6; j++)
        {
            scanf("%d", &puz[i][j]);
        }
    }

    //find 1

    int loc_car_l;
    int loc_car_r;
    bool flag = false;

    for(int i = 1; i <= 6; i++)
    {
        if(puz[3][i] == 1 && !flag)
        {
            flag = true;
            loc_car_l = i;
        }

        if(puz[3][i] == 1 && (puz[3][i+1] != 1 || i > 6))
        {
            loc_car_r = i;
            break;
        }
    }

    dfs(loc_car_l, loc_car_r, 1 , 1, 3);

    if(cnt >= 10)
        printf("-1\n");
    else
        printf("%d\n", cnt);

    return 0;
}
