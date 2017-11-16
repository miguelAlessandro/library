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

long long Pollards_Rho(long long n, int k){
 
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

///////////////////////////////////////////////////// Complexity: O(n^0.25)
long long Phollard_Brend_Rho(long long n){
  long long x_fixed = 2, x = 2, factor = 1;
  long long cycle_size = 2;
	while (factor == 1){
    
		for (int i = 1; i <= cycle_size and factor <= 1; ++i){
			x = add(mul(x, x, n), 1, n);
			factor = gcd(abs(x - x_fixed), n);
		}

		cycle_size <<= 1;
		x_fixed = x;
	}
  
  return factor;
}




