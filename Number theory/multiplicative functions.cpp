/*
  let f a multiplicative function
  
  *************************
    f[1] = 1 
    f[p . q] = f[p] . f[q] if gcd(p, q) = 1
  *************************

  find f[ [1, ..., n] ]
  Complexity: O(n)
*/


//case 1: it is know f[p . i] with p prime
bool composite[N];
int Mobius[N];
prime<int> prime;

void sieve_mf(int n){
  
  Phi[1] = 1;
  for(int i = 2; i <= n; ++i){
    if(not composite[i]){
      prime.push_back(i);
      Phi[i] = i - 1;
    }
    
    for(int p : prime){
      if(p * i > n) break;
      
      composite[p * i] = 1;
      
      if(i % p == 0){
        phi[p * i] = p * phi[i];
        break;
      }
  
      phi[p * i] = phi[p] * phi[i];
    }
  }
}

//case 2: it is know f[p ^ k] with p prime 

void sieve_mf(int n){
  
  Phi[1] = 1;
  for(int i = 2; i <= n; ++i){
    if(not composite[i]){
      prime.push_back(i);
      Phi[i] = i - 1;
      ex[i] = i;
    }
    
    for(int p : prime){
      if(p * i > n) break;
      
      composite[p * i] = 1;
      
      if(i % p == 0){
        phi[p * i] = phi[i / ex[i]] * (ex[i] * phi[p]);
        ex[p * i] = p * ex[i];
        break;
      }
    
      phi[p * i] = phi[p] * phi[i];
      ex[p * i] = p;
    }
  }
}





