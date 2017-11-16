/*
  Discrete logarithm
  
  find x in: a^x = b (mod m)
  
  Complexity: O(sqrt m . log m) / [best : O(sqrt m) use hashing]
*/


int discrete_logarithm (int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;

    int an = 1;
    for (int i = 0; i < n; ++i)
        an = mul(an, a, m);

    map<int,int> vals;
    for (int i = 1, cur = an; i <= n; ++i){
        if (not vals.count(cur))
            vals[cur] = i;
            
        cur = mul(cur, an, m);
    }

    for(int i = 0, cur = b; i <= n; ++i) {
        if(vals.count(cur)) {
            int ans = vals[cur] * n - i;
            if (ans < m)
                return ans;
        }
        
        cur = mul(cur, a, m);
    }
    
    return -1;
}
