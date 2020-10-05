#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

bool isvis[MAXN+10];
vector <int> edge[MAXN+10];
int dis[MAXN+10]; // dis to all node
int dis_son[MAXN+10]; // dis to all child node
int num[MAXN+10]; // how many node, init 1
int Num_TreeNode;

void treeDP(int k){
	isvis[k] = true;
	for(int i = 0 ; i < edge[k].size() ; i++ ){
		int tmp = edge[k][i];
		if( isvis[tmp] )
			continue;
		treeDP(tmp);
		cout << k << " " << tmp << endl;
		num[k] += num[tmp];
		dis_son[k] += num[tmp] + dis_son[tmp];
	}
}

void FullRange(int k){
	isvis[k] = true;
	for(int i = 0 ; i < edge[k].size() ; i++ ){
		int tmp = edge[k][i];
		if( isvis[tmp] )
			continue;
		dis[tmp] = dis[k] + Num_TreeNode - 2*num[tmp];
		FullRange(tmp);
	}
}

int main(){
	
	scanf("%d", &Num_TreeNode );
	for(int i = 0 ; i < Num_TreeNode ; i++)
		edge[i].clear();
	
	int u,v;
	for(int i = 0 ; i < Num_TreeNode-1 ; i++ ){
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	memset(isvis,0,sizeof(isvis));
	memset(dis_son,0,sizeof(dis_son));
	for(int i = 0 ; i < Num_TreeNode ; i++ )
		num[i] = 1;
	treeDP(0);
	
	memset(dis,0,sizeof(dis));
	dis[0] = dis_son[0];
	memset(isvis,0,sizeof(isvis));
	FullRange(0);

}
