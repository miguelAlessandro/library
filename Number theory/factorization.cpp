/*
  factorization:
  
  factorice n:
  
  n = (p_1 ^ a_1) . (p_2 ^ a_2) ... (p_k ^ a_k) 
  
*/


//case 1: Complexity O(n) preprocessing, O(log(n)) query

bool composite[N];
vector<int> prime;
int Min[N];

//preprocesing
void sieve_min(int n){

  for(int i = 2; i <= n; ++i){
    if(not composite[i]){
      prime.push_back(i);
      Min[i] = i;
    }
  
    for(int p : prime){
      if(i * p > n) break;
      composite[i * p] = 1;
      Min[i * p] = p;
      if(i%p == 0) break;
    }
  }
}

//query
typedef pair<int, int> ii;
vector<ii> factorization(int n){
  
  vector<ii> ans;
  while(Min[n]){
    int p = Min[n];
    int e = 0;
    
    while(n % p == 0){
      e += 1;
      n /= p;
    }
    
    ans.push_back({p, e});
  }
  
  return ans;
}

//case 2: Complexity preprocessing: O(sqrt(n)), query: O(sqrt(n) / log(n)) 

//preprocessing:
sieve(sqrt(maxN) + 1.);

//query:
vector<ii> query(int n){

  vector<ii> ans;
  for(int p : prime){
    if(p*p > n) break;
    if(n % p == 0){
      int e = 0;
      while(n%p == 0){
        e += 1;
        n /= p;
      }
      ans.push_back({p, e});
    }
  }
   
  if(n > 1) ans.push_back({n, 1});
  return ans;
}

//case 3: (probabilistic case) query: O(n^0.25 * log^2(n)) [best: O(n^0.25 * log10 n )]

vector<ii> query(int n){
  
  vector<ii> ans;
  
  while(n != 1){
    if(Miller_Rabin(n, 20)){
      ans.push_back({n, 1});
      break;
    }
    
    int d = Pollards_Rho(n, 10);
    int e = 0;
    while(n%d == 0){
      e += 1;
      n /= d;
    }
    
    ans.push_back({d, e});
  }
  
  return ans;
}

