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

int main(){


    int cases;
    int n;
    cin >> cases;


    while(cases--){

        priority_queue< int, vector<int>, greater<int> > pq;
        cin >> n;
        int tmp;
        for(int i = 0 ; i < n ; i++){

            cin >> tmp;
            pq.push(tmp);
        }
        int ans = 0;
        while(pq.size()>1){

            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += (a+b);
            pq.push(a+b);
        }
        cout << ans << endl;


    }

    return 0;
}
