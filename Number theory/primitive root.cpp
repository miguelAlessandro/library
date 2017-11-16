/*
  primitive root
  
  find primitive root g mod p 
 
  p = 1, 2, 4 or
  p = a . prime ^ k \ a in {1, 2}
  
*/

vector<int> prime_factors(int p){
 
  if(p == 2 or p == 4)
    return vector<int>(1, 2);
   
  vector<int> ans; 
  if(p%2 == 0){
    p >>= 1;
    
    if(p%2 == 0) return vector<int>();
    ans.push_back(2);
  }
  
  for(int i = 3; i*i <= p; i += 2)
      if(p%i == 0){
          while(p%i == 0) p /= i;
          
          ans.push_back(i);
      }
      
  if(p > 1) ans.push_back(p);
  if(ans.size() == 1) return ans;
  if(ans.size() == 2 and ans[0] == 2) return ans;
  return vector<int>();
}



int generator (int p) {
    
    int Phi = phi(p);
    vector<int> fact = prime_factors(p);

    for (int res = 2; res <= p; ++res){
        bool ok = 1;
        for (int f : fact)
            ok &= expfast(res, Phi / f, p) != 1;
        
        if (ok)  return res;
    }
    return -1;
}
