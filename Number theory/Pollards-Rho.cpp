/*
  Pollards - Rho
  
  n not prime
  find d: 
  n = d . a \ 1 < d < n 
  
  complexity O(n^0.25 . log n)
*/

long long f(long long x, long long c, long long n){
  return add(bimul(x, x, n), c, n);
}

long long PollardsRho(long long n, int k){
 
    if (n==1) return n;
    if (n % 2 == 0) return 2;
 
    while(k--){
      long long x = rand(n-2) + 2, y = x;
      long long c = rand(n-1) + 1;
      long long int d = 1;  
 
      while(d == 1){
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
       
        d = gcd(abs(x-y), n);
 
        if (d == n)
          break;
      }
      
      if(d != n) break;
    }
        
    return d;
}
