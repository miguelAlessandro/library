/*
  chinese remainder theorem
  
  solve:
        x = a_i (mod b_i)
        1 <= i <= n;
   
    // m = b_1 . b_2 ... b_n <= 10^18
   
    complexity: O(n log m)  
*/

long long CRT(int a[], int b[], int n){

    long long ans = a[0], m = b[0];

    for(int i = 1; i < n; ++i){
        long long x = invmod(m, b[i]);
        long long y = invmod(b[i], m);
        long long M = m * b[i];

        ans = mul(mul(ans, y, M), b[i], M);
        ans = add(ans, mul(a[i], mul(x, m, M), M), M);
        m = M;
    }
    
    return ans;
}
