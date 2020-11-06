#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 20
//注意，f0=1,f1=1,f2=2...
LL mod=1e9+7; // 避免數值過大造成 overflow，因此將所有數值都 mod 10^9+7 
LL d;
vector<LL> vco;
vector<LL> van;
struct Matrix  { 
	LL a[maxn][maxn];
	void all_0() // 清空矩陣 
	{
		memset(a, 0, sizeof(a));
	}
	void I() // 讓矩陣變成單位方陣 
	{
		for (int i = 0; i < maxn; ++i)
		{
			for (int j = 0; j < maxn; ++j)
			{
				if (i==j)	a[i][j]=1;
				else a[i][j]=0;
			}
		}
	}
	void ini() // 讓矩陣變成文章中的矩陣 A
	{
		memset(a,0,sizeof(a));
		for (int i = 0 ; i < d ; ++i)	a[0][i] = vco[i];
		for (int i = 1 ; i < d ; ++i)	a[i][i-1] = 1 ;
		// a[0][0]=1; a[0][1]=1;
		// a[1][0]=1; a[1][1]=0;
	}
};

Matrix operator*(const Matrix &a, const Matrix &b) // 矩陣乘法
{
	Matrix ret;
	ret.all_0();
	for (LL i=0; i<d; i++)  {
		for (LL j=0; j<d; j++)  {
			for (LL k=0; k<d; k++)  {
				ret.a[i][j]+=a.a[i][k]*b.a[k][j];
				ret.a[i][j]%=mod;
			}
		}
	}
	return ret;
}

Matrix power(Matrix a, LL n) // 快速冪 
{
	Matrix ret;
	ret.I();
	if (n==0)  return ret;
	ret.ini();
	if (n==1)  return ret;
	ret=power(a, n/2);
	// printf("n==%lld\n",n );
	ret=ret*ret;
	if (n%2==1)  ret=ret*a;
	return ret;
}

LL query(LL n)
{
	Matrix tmp;
	van.clear();
	vco.clear();
	LL tin;

	for (int i = 0; i < d; ++i)
	{
		scanf("%lld",&tin);
		vco.push_back(tin);
	}
	for (int i = 0; i < d; ++i)
	{
		scanf("%lld",&tin);
		van.push_back(tin);
	}
	if (n-d<=0)	return van[n-d];

	tmp.ini();
	tmp=power(tmp, n-d);

	LL ret=0;
	for (int i = 0; i < d; ++i)
	{
		ret+=tmp.a[0][i]*van[d-i-1];

	}
	ret=(ret+mod)%mod;
	return ret;
}

int main()
{
	LL n;
	while (scanf("%lld %lld %lld" , &d, &n, &mod)&&(d!=0 || n!=0 || mod !=0))  {
		//d 是多深(3的話就3個相加) n代表求第n項
		cout << query(n) << endl;
	}
	return 0;
}
