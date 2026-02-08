template<class T> struct Matrix {
  ll nr, nc;
  vector<vector<T>> arr;

  Matrix(){
    Matrix(0, 0);
  }

  Matrix(size_t n, size_t m){
    nr = n;
    nc = m;
    arr.assign(n, vector<T>(m));
  }

  Matrix(size_t n, size_t m, const vector<vector<T>>& a){
    nr = n;
    nc = m;
    arr = a;
    assert(a.size()==n);
    rep(i, n) assert(a[i].size()==m);
  }

  Matrix transpose(){
    Matrix<T> ret(nc, nr);
    rep(i, nc) rep(j, nr) ret[i][j] = (*this)[j][i];
    return ret;
  }

  vector<T>& operator[](ll i){ // 非const版
    return this->arr[i];
  }

  const vector<T>& operator[](ll i) const { // const版
    return this->arr[i];
  }

  Matrix operator*(const Matrix& b) const {
    const Matrix& a = *this;
    assert(a.nc == b.nr);
    ll nr = a.nr;
    ll nc = b.nc;
    Matrix ret(nr, nc);
    rep(i, nr) rep(k, b.nc) {
      T val = 0;
      rep(j, a.nc) {
        val += a[i][j]*b[j][k];
        ret[i][k] = val;
      }
    }
    return ret;
  }

  Matrix pow(ll n) const {
    assert(this->nr == this->nc);
    ll nx = this->nr;
    Matrix cum = *this;
    Matrix ret(nx, nx);
    rep(i, nx) ret[i][i] = 1;
    while (n > 0) {
      if ((n & 1) == 1) ret = cum*ret;
      if (n == 1) break;
      cum = cum*cum;
      n >>= 1;
    }
    return ret;
  }

  // Gauss-Jordan (gj) a bang method
  // returns the rank (rk) and determinant (dt, only if nr==nc)
  void gj(bool is_extended, ll& rk, T& dt){
    Matrix& a = *this;
    ll rank = 0;
    T det = 1;
    ll jmax = a.nc;
    if(is_extended) jmax--;
    rep(j, jmax){
      repE(i, rank, a.nr-1){
        if(a[i][j] != 0){
          if(i != rank) det *= -1;
          swap(a[i], a[rank]);
          assert(a[rank][j]!=0);
          rep(k, a.nc){
            if(k!=j) a[rank][k] /= a[rank][j];
          }
          det *= a[rank][j];
          a[rank][j] = 1;
          rep(k, a.nr) if(k!=rank) {
            if(a[k][j].x != 0) {
              T c = a[k][j];
              rep(l, a.nc){
                a[k][l] -= a[rank][l]*c;
              }
              assert(a[k][j]==0);
            }
          }
          rank++;
          break;
        }
      }
    }
    if(a.nr != a.nc || rank < a.nr) det = 0;

    // output assignment
    rk = rank;
    dt = det;
  }

  // solve the linear equation given as an
  // extended coefficient matrix.
  // returns
  // - feasibility as the return value (feasible, i.e. whether solvable)
  // if feasible, 
  // - a solution (c)
  // - the dimension (dims) the solution space
  // - basis (b) of the solution space
  bool solve(Matrix& c, ll& dims, Matrix& b){
    Matrix a = *this;
    ll rk;
    T dt; // unused
    a.gj(true, rk, dt);

    ll n = a.nr;
    ll m = a.nc-1;
    Matrix ce(m+1, 1);
    ce[m][0] = 1;

    set<ll> st;
    map<ll, ll> mp;
    rrepE(i, n-1, 0){
      rep(j, m){
        if(a[i][j]==1){
          st.insert(j);
          mp[i] = j;
          repE(jj, j+1, m){
            ce[j][0] -= a[i][jj]*ce[jj][0];
          }
          break;
        }
      }
    }

    dims = m-rk;
    b = Matrix(m, dims);
    ll nb = 0;
    rep(j, m) if(!st.count(j)) {
      b[j][nb] = 1;
      rep(i, n) {
        if(mp.count(i)) b[mp[i]][nb] = -a[i][j];
      }
      nb++;
    }

    c = Matrix(m, 1);
    rep(i, m) c[i] = ce[i];

    bool feasible = true;
    rep(i, n) {
      T sm = 0;
      rep(j, m+1){
        sm += a[i][j]*ce[j][0];
      }
      feasible &= (sm==0);
      if(!feasible) break;
    }
    
    return feasible;
  }

};
