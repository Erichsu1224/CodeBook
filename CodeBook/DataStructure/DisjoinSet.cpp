#define SIZE 10000

struct disjoint{
	
	int arr[SIZE+10];
	
	void init(){
		memset(arr,-1,sizeof(arr));
	}

	int find(int k){
		return arr[k]<0 ? k:(arr[k]=find(arr[k]));
	}

	void uni(int a, int b){
		a = find(a);
		b = find(b);
		arr[a] += arr[b];
		arr[b] = a;
	}

	int siz(int k){
		return (-arr[find(k)])
	}

}D;

