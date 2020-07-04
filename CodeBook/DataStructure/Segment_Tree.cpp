int st[maxn];
int st_val[maxn];

void build(int now, int l, int r){
	if(l == r)
		st[now] = st_val[l];
	else{
		build(now*2, l, (l+r)/2);
		build(now*2+1, (l+r)/2+1), r);
		st[now] = max(st[now*2], st[now*2]+1);
	}
}

int query(int now, int l, int r, int t_l, int t_r){
	
	int tmp = -1e9;

	if(t_l <= l && r <= t_r)
		return st[now];

	if(t_l <= (l+r)/2)
		tmp = max(tmp, query(l, (l+r)/2, t_l, t_r));

	if(t_r > (l+r)/2)
		tmp = max(tmp, query((l+r)/2+1, r, t_l, t_r));

	return tmp;
}

void update(int now, int l, int r, int tar){

	if(l == r){
		st[now] = st_val[l];
		return;
	}

	if(tar <= (l+r)/2)
		update(l, (l+r)/2, tar);

	if(tar > (l+r)/2)
		update((l+r)/2+1, r, tar);

	st[now] = max(st[now*2], st[now*2]+1);
}