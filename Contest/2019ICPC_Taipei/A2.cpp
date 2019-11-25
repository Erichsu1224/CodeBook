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

#define ROW 0
#define COL 1

int puz[10][10];
bool flag;
int ans;

int findDir(int x, int y){

    if(puz[x][y+1] == puz[x][y] || puz[x][y-1] == puz[x][y])
        return ROW;
    else
        return COL;
}

void dfs(int tail, int head, int dir, int line, int cnt){

    printf("%d %d %d %d %d\n", tail, head, dir, line, cnt);

    if(cnt > 8)
        return;
    if(puz[3][6] == 1)
    {
        flag = true;
        ans = min(ans, cnt+2);
        return;
    }

    if(head > tail){
        //right down
        if(dir == ROW){

            if(puz[line][head+1] == 0){

                cout << "move r" << endl;
                //move right
                if(head + 1 > 6)
                    return;
                cnt++;
                puz[line][head+1] = puz[line][head];
                puz[line][tail] = 0;

                head = head+1;
                tail = tail+1;
            }
            else{
                //has car
                cout << "row has c" << endl;
                int tmp = findDir(line, head+1);
                if(tmp == ROW){

                    //car in row
                    if(puz[line][head+3] != puz[line][head+1])
                        dfs(head+1, head+2, ROW, line, cnt);
                    else
                        dfs(head+1, head+3, ROW, line, cnt);
                }
                else{

                    //car in col
                    int t = line;
                    int d = line;
                    for(int i = line ; i >= 1 ; i--){

                        if(puz[i][head+1] == puz[line][head+1])
                            t = i;
                    }
                    for(int i = line ; i <= 6 ; i++){

                        if(puz[i][head+1] == puz[line][head+1])
                            d = i;
                    }
                    dfs(t, d, COL, head+1, cnt);
                    dfs(d, t, COL, head+1, cnt);
                }
            }
        }
        else{

            if(puz[head+1][line] == 0){

                // move down
                cout << "move d" << endl;
                if(head + 1 > 6)
                    return;

                puz[head+1][line] = puz[head][line];
                puz[tail][line] = 0;
                cnt++;
                head++;
                tail++;
            }
            else{

                cout << "d has c" << endl;
                int tmp = findDir(head+1, line);
                if(tmp == ROW){

                     int l, r;
                     for(int i = line ; i >= 1 ; i--){

                        if(puz[head+1][i] == puz[head][line])
                            l = i;
                    }
                    for(int i = line ; i <= 6 ; i++){

                        if(puz[head+1][i] == puz[head+1][line])
                            r = i;
                    }
                    dfs(l, r, ROW, head+1, cnt);
                    dfs(r, l, ROW, head+1, cnt);
                    //car in row

                }
                else{

                    //car in col
                    if(puz[head+1][line] != puz[head+3][line])
                        dfs(head+1, head+2, COL, line, cnt);
                    else
                        dfs(head+1, head+3, COL, line, cnt);
                }
            }
        }
    }
    else{
         if(dir == ROW){

            if(puz[line][head+1] == 0){

                cout << "move left" << endl;
                //move left
                if(head - 1 < 1)
                    return;

                puz[line][head-1] = puz[line][head];
                puz[line][tail] = 0;
                cnt++;
                head--;
                tail--;
            }
            else{
                //has car
                cout << "l has c" <<endl;
                int tmp = findDir(line, head-1);
                if(tmp == ROW){

                    //car in row
                    if(head - 3 < 1 || head - 2 < 1)
                        return;
                    if(puz[line][head-3] != puz[line][head-1])
                        dfs(head-2, head-1, ROW, line, cnt);
                    else
                        dfs(head-3, head-1, ROW, line, cnt);
                }
                else{

                    //car in col
                    int t = line;
                    int d = line;
                    for(int i = line ; i >= 1 ; i--){

                        if(puz[i][head-1] == puz[line][head-1])
                            t = i;
                    }
                    for(int i = line ; i <= 6 ; i++){

                        if(puz[i][head-1] == puz[line][head-1])
                            d = i;
                    }
                    dfs(t, d, COL, head-1, cnt);
                    dfs(d, t, COL, head-1, cnt);
                }
            }
        }
        else{

            if(puz[head-1][line] == 0){

                cout << "move up" << endl;
                // move up
                if(head - 1 < 1)
                    return;
                puz[head-1][line] = puz[head][line];
                puz[tail][line] = 0;
                head--;
                tail--;
            }
            else{

                int tmp = findDir(head-1, line);
                if(tmp == ROW){

                     int l, r;
                     for(int i = line ; i >= 1 ; i--){

                        if(puz[head-1][i] == puz[head][line])
                            l = i;
                    }
                    for(int i = line ; i <= 6 ; i++){

                        if(puz[head-1][i] == puz[head+1][line])
                            r = i;
                    }
                    dfs(l, r, ROW, head-1, cnt);
                    dfs(r, l, ROW, head-1, cnt);
                    //car in row

                }
                else{

                    //car in col
                    if(puz[head-1][line] != puz[head-3][line])
                        dfs(head-2, head-1, COL, line, cnt);
                    else
                        dfs(head-3, head-1, COL, line, cnt);
                }
            }
        }



    }
    cout << "nothing happen" << endl;
    dfs(tail, head, dir, line, cnt);
}

int main()
{
    ans = 1e9;
    memset(puz, -1, sizeof(puz));
    for(int i = 1 ; i <= 6 ; i++){

        for(int j = 1 ; j <= 6 ; j++){

            scanf("%d", &puz[i][j]);
        }
    }

    int tail = 0;

    for(int i = 1 ; i <= 6 ; i++){

         if(puz[3][i] == 1){

            tail = i;
            break;
         }
    }
    dfs(tail, tail+1, ROW, 3, 0);

    if(flag)
        printf("%d\n", ans);
    else
        printf("-1\n");

    return 0;
}
