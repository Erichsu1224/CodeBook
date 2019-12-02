#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
	ll t1,t2,a1,a2,b1,b2;
	while(~scanf("%lld %lld %lld %lld %lld %lld",&t1,&t2,&a1,&a2,&b1,&b2)){
		ll cmp1 = (t1*(a1-b1));
		ll cmp2 = (t2*(a2-b2));

		if ((t1*a1+t2*a2)==(t1*b1+t2*b2))
		{
			printf("infinity\n");
			continue;
		}
		if ( (cmp1>0 && cmp2>0) || (cmp1<0 && cmp2<0) || cmp1==0 ||cmp2==0) 
		{
			printf("0\n");
			continue;
		}
		// printf("%lld %lld\n%lld %lld\n",(t1*a1+t2*a2),(t1*b1+t2*b2),cmp1,cmp2);
		if (cmp1<0)
		{
			ll abscmp1 = -cmp1;

			if (abscmp1>cmp2)
			{
				printf("0\n");
				continue;
			}
			
			if (abscmp1%(cmp1+cmp2))
			{
				printf("%lld\n",(abscmp1/(cmp1+cmp2))*2+1 );
			}
			else{
				printf("%lld\n",(abscmp1/(cmp1+cmp2))*2 );
			}
			
		}
		else{
			ll abscmp2 = -cmp2;

			if (cmp1 > abscmp2)
			{
				printf("0\n");
				continue;
			}

			if (cmp1% -(cmp1+cmp2))
			{
				printf("%lld\n",(cmp1/-(cmp1+cmp2))*2+1 );
			}
			else{
				printf("%lld\n",(cmp1/-(cmp1+cmp2))*2 );
			}

		}

	}
	return 0;
}