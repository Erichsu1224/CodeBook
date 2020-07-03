// C++ code to demonstrate operations of Binary ind Tree 
#include <bits/stdc++.h> 
using namespace std; 
#define maxn 10000

int BIT[maxn+5];
int node[maxn+5] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
int n = 12;	//# of node

int getsum(int ind) 
{ 
	int sum = 0;
	ind = ind + 1; 
	while (ind>0) { 
		sum += BIT[ind]; 
		ind -= ind & (-ind); 
	} 
	return sum; 
} 

void update(int ind, int val) 
{ 
	ind = ind + 1; //bcz BIT ind from 1
	while (ind <= n) { 
		BIT[ind] += val; 
		ind += ind & (-ind); 
	} 
} 

void init() 
{ 
	memset(BIT,0,sizeof(BIT));
	for (int i=0; i<n; i++) 
		update(i, node[i]);
} 

int main() 
{ 
	init(); 
	getsum(5);//sum of arr[0~5]
	// update both arr && BIT of node[3]
	node[3] += 100; 
	update(3, 100);
	return 0; 
}
