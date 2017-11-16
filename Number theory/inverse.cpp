/* modular inverse
    
    find x in: ax = 1 (mod b)

    asume gcd(a, b) == 1
*/

//complexity O(log phi(b))
int invmod(int a, int b){
    return expfast(a, phi(b) - 1, b);
}

//complexity O(log max(a, b))
int invmod(int a, int b){
  int x, y;
  int g = gcdex(a, b, x, y);
  
  return (x%b + b)%b;
}
