#include <iostream>
#include <vector>
#include <string>
using namespace std;
void LCS(string x, string y, int**& z, char**& s);
void print_LCS(char** s, string x, int l1, int l2);

int main(int argc, char const *argv[])
{
    string x = "ABCBDAB";
    string y = "BDCABA";
    int** z;
    char** s;
    LCS(x, y, z, s);
    print_LCS(s, x, x.size()-1, y.size()-1);
    return 0;
}

//z[i,j] is the longest length of x[0,i] y[0,j], s[i,j] is the solution
void LCS(string x, string y, int**& z, char**& s){
    size_t l1 = x.size();
    size_t l2 = y.size();
    
    z = new int* [l1+1];
    for (int i = 0; i < l1+1; ++i)
    {
        *(z + i) = new int[l2+1];
        memset(*(z+i), 0, (l2+1)*sizeof(int));
    }
    
    s = new char* [l1];
    for (int i = 0; i < l1; ++i)
    {
        *(s + i) = new char[l2];
        memset(*(s+i), 0, (l2)*sizeof(char));
    }
    
    //i means x[0:i-1]
    for (int i = 0; i < l1; ++i)
    {
        //j means y[0:j-1]
        for (int j = 0; j < l2; ++j)
        {
            if(x[i] == y[j]){
                z[i+1][j+1] = z[i][j] + 1;
                s[i][j] = '<';
            }else if(z[i][j+1] >= z[i+1][j]){
                z[i+1][j+1] = z[i][j+1];
                s[i][j] = '>';
            }else{
                z[i+1][j+1] = z[i+1][j];
                s[i][j] = '?';
            }
        }
    }
}

void print_LCS(char** s, string x, int l1, int l2){
	if(-1 == l1 || -1 == l2){
		return;
	}else if('<' == s[l1][l2]){
		print_LCS(s, x, l1-1, l2-1);
		std::cout << x[l1];
	}else if('>' == s[l1][l2]){
		print_LCS(s, x, l1-1, l2);
	}else{
		print_LCS(s, x, l1, l2-1);
	}
}
