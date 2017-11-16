/*
  Miller-Rabin primality test
  
  solve: 
      [n is prime]
  
  O(k . log^2(n)) n <= 10^18 // O(k . log n) n <= 10^9
*/

bool Miller_Rabin(long long n, int k){
  if(n%2 == 0) return n == 2;
  if(n <= 7) return n != 1; 

  long long d = n-1;
  int r = 0;
  
  while((d&1) == 0){
    r += 1;
    d >>= 1;
  }
 
  while(k--){
  	x = expfast(rand(n - 3) + 2, d, n); 
  	if(x == 1 or x == n-1) continue;
  
    	for(int i = 0; i < r; ++i){
    		x = bimul(x, x, n);     
     	
		if(x == 1) return 0;
     		if(x == n-1) break;
     	}
  
  	if(x != n-1) return 0;
  }

  return 1;
}
