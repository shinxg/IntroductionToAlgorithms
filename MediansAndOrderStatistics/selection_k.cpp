#include <iostream>
int selection(int* a, int p, int r, int i);
int partition(int* a, int p, int r);

int main(int argc, char const *argv[])
{
	int a[8] = {2,8,7,1,3,5,6,4};
	std::cout << selection(a, 0, 7, 1) << std::endl;

	return 0;
}

int selection(int* a, int p, int r, int i){
	if(p==r){
		return a[p];
	}else{
		int q = partition(a, p, r);
		int k = q - p + 1;
		if(k == i){
			return a[q];
		}else if(k > i){
			return selection(a, p, q-1, i);
		}else{
			return selection(a, q+1, r, i-k);
		}
	}
}

int partition(int* a, int p, int r){
	int pivot = a[r];
	int i = p-1;
	for (int j = p; j < r; ++j)
	{
		if(a[j] <= pivot){
			i++;
			int t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
	}
	int t = a[i+1];
	a[i+1] = a[r];
	a[r] = t;
	return i+1;
}