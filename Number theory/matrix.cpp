//
  square matrix template.
//

struct matrix{
  vector<int> at;
  int n;
  
  void init(int n){
    this->n = n;
    at.clear();
    at.resize(n, vector<int>(n, 0));
  }

  void Id(){
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        at[i][j] = i==j;
  }

  matrix operator*(const matrix& X){
    matrix R; R.Init(n);
    
    for(int i = 0; i < n; ++i)
        for(int k = 0; k < n; ++k)
          if(at[i][k] != 0)
            for(int j = 0; j < n; ++j)
              R.at[i][j] = add(R.at[i][j], mul(at[i][k], X.at[k][j], mod), mod);
  
    return R;
  }

  friend matrix expfast(matrix& A, long long n){
    matrix R; R.Init(A.n); R.Id();
    while(n > 0){
      if(n&1) R = R * A;
      A = A * A;
      n >>= 1;
    }
    return R;
  }
};
