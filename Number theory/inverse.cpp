//asume gcd(a, b) == 1

int invmod(int a, int b){
    return expfast(a, phi(b) - 1, b);
}

int invmod(int a, int b){
  int x, y;
  int g = gcdex(a, b, x, y);
  
  return (x%b + b)%b;
}
