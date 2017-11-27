#include <iostream>
struct node
{
	int x;
	int isk;
	node* left;
	node* right;
};

void optimal_bst(int* p, int* q, int n, int**& e, int**& w, int**& root);
node* construct_bst(int** root, int i, int j);
void traverse(node* t);

int main(int argc, char const *argv[])
{
	//ki
	int p[6] = {0,15,10,5,10,20};
	//di
	int q[6] = {5,10,5,5,5,10};
	//optimal sum from i to j
	int** e = NULL;
	//percentage from i to j
	int** w = NULL;
	//roots
	int** root = NULL;
	//tree
	node* t = NULL;

	optimal_bst(p, q, 5, e, w, root);
	t = construct_bst(root, 1, 5);
	traverse(t);
	std::cout << std::endl;

	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			std::cout.width(4);
			std::cout << e[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			std::cout.width(4);
			std::cout << w[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			std::cout.width(4);
			std::cout << root[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << e[1][5] << std::endl;
	return 0;
}

void optimal_bst(int* p, int* q, int n, int**& e, int**& w, int**& root){
	//initialize
	e = new int*[n+2];
	for (int i = 0; i < n+2; ++i)
	{
		*(e+i) = new int[n+2];
		memset(*(e+i), 0, sizeof(int)*(n+2));
	}

	w = new int*[n+2];
	for (int i = 0; i < n+2; ++i)
	{
		*(w+i) = new int[n+1];
		memset(*(w+i), 0, sizeof(int)*(n+2));
	}

	for (int i = 1; i < n+2; ++i)
	{
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}

	root = new int*[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		*(root+i) = new int[n+1];
		memset(*(root+i), 0, sizeof(int)*(n+1));
	}

	//length
	for (int l = 1; l <= n; ++l)
	{
		//begin index
		for (int i = 1; i <= n-l+1; ++i)
		{
			//end index
			int j = i + l - 1;
			e[i][j] = INT_MAX;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			for (int r = i; r <= j; ++r)
			{
				int temp = e[i][r-1] + e[r+1][j] + w[i][j];
				if(temp < e[i][j]){
					e[i][j] = temp;
					root[i][j] = r;
				}
			}
		}
	}
}

node* newnode(){
	node* temp = new node();
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node* construct_bst(int** root, int i, int j){
	node* p;
	if(i > j){
		p = NULL;
	}
	else{
		p = newnode();
		int t = root[i][j]; 
		p->x = root[i][j];
		p->isk = 1;
		p->left = construct_bst(root, i, root[i][j]-1);
		p->right = construct_bst(root, root[i][j]+1, j);
	}
	return p;
}

void traverse(node* t){
	if(t){
		if(t->isk){
			std::cout << 'k';
		}else{
			std::cout << 'd';
		}
		std::cout << t->x << "  ";
		traverse(t->left);
		traverse(t->right);
	}
}