#include <iostream>
void find_max_min(int* a, int l, int& whole_max, int& whole_min);

int main(int argc, char const *argv[])
{
	int a[] = {2,8,7,1,3,5,6,4,12,14,28,0};
	int whole_max = 0;
	int whole_min = 0;
	find_max_min(a, sizeof(a)/sizeof(int), whole_max, whole_min);
	std::cout << whole_max << whole_min << std::endl;
	return 0;
}

void find_max_min(int* a, int l, int& whole_max, int& whole_min){
	//l = 2n+1
	if(l%2){
		whole_min = a[0];
		whole_max = a[0];
		//for loop
		for (int i = 1; i < l; i+=2)
		{
			int local_max;
			int local_min;
			if(a[i] > a[i+1]){
				local_max = a[i];
				local_min = a[i+1];
				
			}else{
				local_max = a[i+1];
				local_min = a[i];
			}
			if(local_max > whole_max){
				whole_max = local_max;
			}
			if(local_min < whole_min){
				whole_min = local_min;
			}
		}
	}
	//l = 2n
	else{
		//initial
		if(a[0] > a[1]){
			whole_max = a[0];
			whole_min = a[1];
		}else{
			whole_max = a[1];
			whole_min = a[0];
		}
		//for loop
		for (int i = 2; i < l; i+=2)
		{
			int local_max;
			int local_min;
			if(a[i] > a[i+1]){
				local_max = a[i];
				local_min = a[i+1];
				
			}else{
				local_max = a[i+1];
				local_min = a[i];
			}
			if(local_max > whole_max){
				whole_max = local_max;
			}
			if(local_min < whole_min){
				whole_min = local_min;
			}
		}
	}
}