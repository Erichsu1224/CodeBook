#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int arr[]={105,104,103,102,101,100};
	while(~scanf("%d",&n)){
		while(n%100){
			bool f=false;
			for (int i = 0; i < 6; ++i)
			{
				if (n%100<arr[i]%100 || n<100)
				{
					continue;
				}
				n-=arr[i];
				f=true;
				break;
			}
			if (f==false)
			{
				break;
			}
		}
		if (n%100)
		{
			printf("0\n");
		}
		else{
			printf("1\n");
		}

	}
	return 0;
}