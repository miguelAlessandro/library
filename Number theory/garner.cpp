/*
    Garner Algorithm:
    
    let:
    
        x = a_i (mod p_i)
    
    p_i coprime numbers
    
    then there unique x mod p_1 . p_2 ... p_k

    build x in the form x_1 + x_2 . p_1 + x_3 . p_1 . p_2 + ... x_k . p_1 . p_2 ... p_k-1
    
    complexity O(k*k*log k) / with fast inverse O(k*k)

*/

#include <iostream>
using namespace std;

const int N = 1002;
int r[N][N];
int x[N], a[N], p[N];
int k;

void garner_build(int a[], int p[], int k){

    for(int i = 0; i < k; ++i)
        for(int j = i+1; j < k; ++j)
            r[i][j] = expfast(p[i], p[j] - 2, p[j]);  

    for(int i = 0; i < k; ++i)
        x[i] = a[i];

    for(int i = 0; i < k; ++i)
	    for (int j = 0; j < i; ++j)
		    x[i] = mul(r[j][i], x[i] - x[j], p[i]);
        
    //build solution:
    //bigint ans(0), mul(1);
    //for(int i = 0; i < k; ++i){        
    //    ans = ans + x[i] * mul;    
    //    mul = mul * p[i];
    //}
    //return ans;
}

int main(){

    return 0;
}
