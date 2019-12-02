#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
int arr[100000+5];
int nums[100000+5];

int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d",&n)){
		memset(nums,0,sizeof(nums));
		for (int i = 0; i < n ; ++i)
		{
			scanf("%d",&arr[i]);
			arr[i]++;
		}
		ll ans=1;
		nums[0]=3;
		for (int i = 0; i < n; ++i){
			// printf("arr[%-2d]==%d  3-num[%-2d] == %-2d ,pre numscnt==%-2d  ,min==%-2d\n",i,arr[i],arr[i],3-nums[arr[i]],nums[ arr[i]-1 ],min(3-nums[ arr[i] ],nums[ arr[i]-1 ]) );
			ans=(ans%mod*min(3-nums[ arr[i] ],nums[ arr[i]-1 ]-nums[ arr[i]]))%mod;
			nums[ arr[i] ]++;
	
		}
		printf("%lld\n",ans );
	}
	return 0;
}	