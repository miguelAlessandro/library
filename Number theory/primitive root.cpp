/*
  primitive root
  
  find primitive root g mod p 
 
  p = 1, 2, 4 or
  p = a . prime ^ k \ a in {1, 2}
  
*/

int generator (int p) {
    
    int phi = p-1, n = phi;
    vector<int> fact;
    for(int i = 2; i*i <= n; ++i)
      if(n%i == 0){
        while(n%i == 0) n /= i; 
        fact.push_back(i);
      }
    if(n > 1) fact.push_back(n);
  
    for (int res = 2; res <= p; ++res){
        bool ok = 1;
        for (int f : fact)
            ok &= expfast(res, phi / f, p) != 1;
        
        if (ok)  return res;
    }
    return -1;
}
