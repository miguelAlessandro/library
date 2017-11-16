/*
  fast inverse:
  
  find x_i in:
    x_i.i = 1 (mod n) 
  1 <= i <= m
  
  m <= n <= 10^9.
  complexity: O(m)
  
  n%i = n - {n/i}.i
  inverse{i} = inverse{(n%i)} . {- n/i} [mod n]
  
*/

int r[N];
void fast_inverse(int n, int m){
  r[1] = 1;
  for(int i = 2; i <= m; ++i)
    r[i] = mul(r[n%i], -n/i, n);
}
