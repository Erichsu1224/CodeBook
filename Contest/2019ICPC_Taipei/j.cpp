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

int n, m;
int arr[20];
string num[20];
string ans;
int minn;

void dfs(int now, string val, int cnt)
{

    bitset<505> curr(val);
    bitset<505> numm(num[now]);

    //cout << now << ' ' << cnt << endl;
    //cout << curr << endl;
    //cout << numm << endl;


    if(val == ans)
        minn = min(minn, cnt);

    if(now == m)
        return;
    dfs(now+1, val, cnt);
    dfs(now+1, (curr|numm).to_string(), cnt+1);
}

int main(){

    int cases;
    cin >> cases;
    while(cases--){

        minn = 1e9;
        scanf("%d %d", &n, &m);

        ans = "";

        for(int i = 504; i >= 0; i--)
        {
            ans += "0";
        }
        for(int i = 504; i >= 504-n+1; i--)
        {
            ans[i] = '1';
        }



        //cout << ans << endl;

        string hold;


        for(int i = 0; i < m; i++)
        {

            cin >> num[i];
        }



        dfs(0, "0", 0);

        if(minn == 1e9)
            printf("-1\n");
        else
            printf("%d\n", minn);
    }

    return 0;
}
