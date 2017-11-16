/* expfast:
  
    fast pow 
    
    find: x = a^n (mod m) 
    
    if n = b_0 + b_1 . 2 + b_2 . 4 + ... 
    
    then x = a . b_0 + a^2 . b_1 + a^4 . b_2 + ...
 
    O(log n)
*/

int add(int a, int b, int mod){
    a = (a%mod + mod)%mod;
    b = (b%mod + mod)%mod;
    
    return (a+b)%mod;
}

int mul(long long a, long long b, int mod){
  a = add(a, 0);
  b = add(b, 0);
  return a * b % mod;
}

int expfast(int a, long long b, int mod){
    int r = 1;
    while(b > 0){
        if(b & 1) r = mul(r, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return r;
}
