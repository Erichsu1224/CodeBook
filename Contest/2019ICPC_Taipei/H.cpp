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

    int t;
    ll n,b,a;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        b = n+1;
        a = n*(n+1);
        printf("%lld\n",b^a);

    }
    return 0;
}
