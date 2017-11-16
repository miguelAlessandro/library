/*
  Discrete root
  
  find all solutions of:
  
  x^k = a (mod n) \ n prime

  
*/

vector<int> discrete_root(int n, int k, int a)

    if(a == 0)
      return vector<int>(1, 0);
    
    int g = generator (n);
    int any_ans = discrete_logarithm(expfast(g, k, n), a, n);
    
    if (any_ans == -1)
        return vector<int>();

    int delta = (n-1) / gcd (k, n-1);
    vector<int> ans;
    for (int cur = any_ans%delta; cur < n-1; cur += delta)
        ans.push_back(expfast(g, cur, n));
        
    sort(ans.begin(), ans.end());    
    return ans;
}
