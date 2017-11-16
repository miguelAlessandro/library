int phi(int n){
  int Phi = n;
  for(int i = 2; i*i <= n; ++i)
    if(n%i == 0){
      while(n%i == 0) n /= i;
      Phi -= Phi / i;
    }

  if(n > 1) Phi -= Phi / n;
  return Phi;
}
