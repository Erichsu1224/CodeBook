#include <bits/stdc++.h>
using namespace std;
string in;

bool findstr(int num){
	int div=100;
	int cnt=0;
	for (int i = 0; i < in.length(); ++i)
	{
		if (in[i]-'0'==num/div)
		{
			// printf("in[%d]=%c %d/%d==%d\n",i,in[i],num,div,num/div );

			cnt++;
			num-=(num/div)*div;
			div/=10;
		}

		if (cnt==3)
		{
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d",&n)){
		
		cin>>in;
		int ans=0;
		for (int i = 0; i < 1000; ++i)
		{
			if (findstr(i))
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}