#include <iostream>
void cut_rod(const int* p, int *r, int* s, int n);

int main(int argc, char const *argv[])
{
	int p[11] = {0,1,5,8,9,10,17,17,20,24,30};
	int r[11] = {0};
	int s[11] = {0};
	cut_rod(p, r, s, 7);
	for (int i = 0; i < 11; ++i)
	{
		std::cout << i << ": " << r[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

//p is the price, r is max profit, s mean solution, n is the length of the rod
void cut_rod(const int* p, int *r, int* s, int n){
	//i = length
	for (int i = 1; i <= n; ++i)
	{
		//j is cut place
		for (int j = 1; j <= i; ++j)
		{
			if(r[i] < p[j] + r[i-j]){
				r[i] = p[j] + r[i-j];
				s[i] = j;
			}
		}
	}

	std::cout << "solution" << std::endl;
	while(n>0){
		std::cout << s[n] << " ";
		n = n - s[n];
	}
	std::cout << std::endl;
}