#include<bits/stdc++.h>

using namespace std;

#define PROBLEM "1650"
#define mod 1000000007

string str;
long long dp[1005][1005];
long long sum[1005][1005];
int len = 0;

void build(){

	len = str.size()+1 ;

	dp[1][1]  = 1;
	sum[1][1] = 1;

	for(int i = 2 ; i <= len ; i++){

		for(int j = 1 ; j <= i ; j++){

			if(str[i-2] == 'D' || str[i-2] == '?'){

				dp[i][j] = (dp[i][j] + sum[i-1][i-1] - sum[i-1][j-1]) % mod;
				// for(int k = j ; k < i ; k++){

				// 	dp[i][j] += dp[i-1][k];
				// 	dp[i][j] %= mod;
				// }
			}
			if(str[i-2] == 'I' || str[i-2] == '?'){

				dp[i][j] = (dp[i][j] + sum[i-1][j-1]) % mod;
			}
			sum[i][j] = (dp[i][j] + sum[i][j-1]) % mod;	
		}
	}
}

int main(){
	
	#ifdef DBG
	freopen("UVA" PROBLEM ".in", "r", stdin);
	freopen("UVA" PROBLEM ".out", "w", stdout);
	#endif

	while(cin >> str){

		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		build();
		cout << (sum[len][len]+mod)%mod << endl;
	}

	return 0;
}