/*
  extended gcd
  
  ax + by = gcd(a, b)
  
  find x, y, gcd(a,b);
  complexity: O(log( max(a, b) ))
*/

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

// ax + by = gcd(a, b)
int gcdex(int a, int b, int& x, int &y){
  if(b == 0){
    x = 1;
    y = 0;
    return a;
  }

  int x_1, y_1;
  int g = gcdex(b, a%b, x_1, y_1);
  x = y_1;
  y = x_1 - (a/b)*y_1;
  return g;
}
