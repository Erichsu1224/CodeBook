#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d",&n)){
		bool f=false;
		for (int i = n; i >0 ; --i)
		{
			if ((int)((double)i*1.08)==n)
			{
				printf("%d\n",i );
				f=true;
				break;

			}
		}
		if (!f)
		{
			printf(":(\n");
		}
	}
	return 0;
}