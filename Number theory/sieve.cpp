/*
  Eratosthenes sieve
  
  find primes in range [1, ..., n]
  
  Complexity: O(n)
*/

vector<int> prime;
bool composite[N];

void sieve(int n){

  for(int i = 2; i <= n; ++i){
    if(not composite[i])
      prime.push_back(i);
    
    for(int p : prime){
      if(p * i > n) break;
      composite[p * i] = 1;
      if(i % p == 0) break;
    }
  }
}
