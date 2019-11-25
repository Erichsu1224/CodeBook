
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define PII par<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()

int n,arr[200];

bool jjj(){
    for(int i=0 ; i<n ;i++){
        for(int j=0 ; j<n ;j++){
                if(i==j) continue;
            for(int k=0 ; k<n ;k++){
                if(i==j||j==k || i==k) continue;
                if((arr[i]-arr[j])%arr[k]){
                    //printf("%d %d %d\n",i,j,k);
                    return false;
                }
    }
    }
    }
    return true;
}

int main(void)
{

    memset(arr,0,sizeof(arr));
    while(~scanf("%d",&n)){
        for(int i=0 ; i<n ;i++){
            scanf("%d",&arr[i]);
        }
        if(jjj()){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }

    }
}
