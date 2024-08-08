template <class T>
struct Matrix {
  vector<vector<T>> A;

  Matrix() {}

  Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}

  Matrix(size_t n) : A(n, vector<T>(n, 0)){};

  size_t height() const { return (A.size()); }

  size_t width() const { return (A[0].size()); }

  inline const vector<T> &operator[](ll k) const { return (A.at(k)); }

  inline vector<T> &operator[](ll k) { return (A.at(k)); }

  static Matrix I(size_t n){
    Matrix mat(n);
    for (ll i = 0; i < n; i++)
      mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B){
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (ll i = 0; i < n; i++)
      for (ll j = 0; j < m; j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B){
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (ll i = 0; i < n; i++)
      for (ll j = 0; j < m; j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B){
    size_t n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vector<vector<T>> C(n, vector<T>(m, 0));
    for (ll i = 0; i < n; i++)
      for (ll j = 0; j < m; j++)
        for (ll k = 0; k < p; k++)
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
    A.swap(C);
    return (*this);
  }

  Matrix &operator^=(long long k){
    Matrix B = Matrix::I(height());
    while (k > 0){
      if (k & 1)
        B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }

  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }

  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }

  Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

  T determinant(){
    Matrix B(*this);
    assert(width() == height());
    T ret = 1;
    for (ll i = 0; i < width(); i++){
      ll idx = -1;
      for (ll j = i; j < width(); j++){
        if (B[j][i] != 0)
          idx = j;
      }
      if (idx == -1) return (0);
      if (i != idx){
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for (ll j = 0; j < width(); j++){
        B[i][j] /= vv;
      }
      for (ll j = i + 1; j < width(); j++){
        T a = B[j][i];
        for (ll k = 0; k < width(); k++){
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};