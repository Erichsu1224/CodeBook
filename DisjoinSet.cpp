#define SIZE 10000

int arr[SIZE];

void init(int n) // give a initial length
{
	for(int i=0; i<n; i++)
		arr[i] = -1;
}

int find(int x)
{ // find the father point
	return arr[x] < 0 ? x : (arr[x] = find(arr[x]));
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);

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
