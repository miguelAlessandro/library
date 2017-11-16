long long bimul(long long a, long long b, long long mod){

  long long r = 0;
  while(b > 0){
    if(b&1) r = add(r, a);
    a = add(a, a);
    b >>= 1;
  }
  return r;
}


long long bimul_fast(long long a, long long b, long long mod){
  a = add(a, 0, mod);
  b = add(b, 0, mod);

  long long r = 0;
  while(b > 0){
    if(b&1) r += a;
    a += a;
    
    if(r >= mod) r -= mod;
    if(a >= mod) a -= mod;
    b >>= 1;
  }
  return r;
}
