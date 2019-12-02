#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int m1,d1,m2,d2;
	while(~scanf("%d %d",&m1,&d1)){
		scanf("%d %d",&m2,&d2);
		if ((d2-d1)==1)
		{
			printf("0\n");
		}
		else{
			printf("1\n");
		}
	}
	return 0;
}