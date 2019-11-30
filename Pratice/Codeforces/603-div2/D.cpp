#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= z; x++)
#define REPP(x, y, z) for(int x = y; x >= z; x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define maxn 200000+5
#define EB emplace_back

//structure

//declaration
// vector<bitset<26> > v;
vector<int> v[26];
//functions
#define SIZE 10000

int arr[maxn];

void init(int n) // give a initial length
{
	for(int i=0; i<n; i++)
		arr[i] = -1;
}

int find(int x)
{ // find the father point
	return arr[x] < 0 ? x : (arr[x] = find(arr[x])); // update every child to the other father
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if(x == y)
		return;

	if(arr[x] <= arr[y])
	{
		arr[x] += arr[y];
		arr[y] = x;
	}
	else
	{
		arr[y] += arr[x];
		arr[x] = y;
	}
}

int main(void)
{
	int n;	scanf("%d\n", &n);

	init(n);
	for(int i = 0; i < 26; i++)
	{
		v[i].clear();
	}

	// v.clear();

	string str;

	REP(i, 1, n)
	{
		bitset<26> tmp(0);

		cin >> str;

		for(int j = 0; j < str.size(); j++)
		{

			// tmp[str[j]-'a'] = 1;
			v[str[j]-'a'].EB(i);
		}

		// v.EB(tmp);
	}

	//test
	// REP(i, 0, n-1)
	// 	cout << v[i] << endl;
	// bitset<26> tmp(0);

	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = i+1; j < n; j++)
	// 	{
	// 		if((v[i] & v[j]) != tmp)
	// 		{
	// 			Union(i, j);
	// 		}
	// 	}
	// }

	for(int i = 0; i < 26; i++)
	{
		for(int j = 1; j < v[i].size(); j++)
		{
			Union(v[i][0], v[i][j]);
		}

	}

	int ans = 0;

	for(int i = 0; i < n; i++)
	{
		if(arr[i] < 0)
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}