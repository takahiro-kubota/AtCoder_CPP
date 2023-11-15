// ll version.
struct bitbasis {
  ll n; // n bit vector
  ll dim = 0;
  vll bs; // assert(bs.size() == n)
  bitbasis(ll _n){
    n = _n;
    bs.assign(n, 0);
  }

  void add(ll x){
    x = minimize(x);
    rrepE(i, n-1, 0){
      if(x>>i&1) {
        rep(j, n) if(bs[j]>>i&1) bs[j] ^= x;
        bs[i] = x;
        dim++;
        return;
      }
    }
  }  

  ll minimize(ll x) { 
    rep(i, n) if(x>>i&1) x ^= bs[i];
    return x;
  }

  ll get(ll x){ // gets x-th smallest val.
    ll ret = 0;
    rep(i, n) {
      if(bs[i] == 0) continue;
      if(x&1) ret ^= bs[i];
      x >>= 1;
    }
    return ret;
  }

};

// vector version.
struct bitbasis {
  ll n; // n bit vector
  ll dim = 0;
  vvll bs; // assert(bs.size() == n)
  bitbasis(ll _n){
    n = _n;
    bs.assign(n, vll(n, 0));
  }

  void add(vll x){
    x = minimize(x);
    rrepE(i, n-1, 0){
      if(!x[i]) continue;
      rep(j, n) {
        if(!bs[j][i]) continue;
        rep(k, n) bs[j][k] ^= x[k];
      }
      bs[i] = x;
      dim++;
      return;
    }
  }  

  vll minimize(vll x) { 
    rep(i, n) if(x[i]) rep(k, n) x[k] ^= bs[i][k];
    return x;
  }

  vll get(ll x){ // gets x-th smallest val.
    vll ret(n, 0);
    rep(i, n) {
      if(bs[i][i] == 0) continue;
      if(x&1){
        rep(k, n) ret[k] ^= bs[i][k];
      }
      x >>= 1;
    }
    return ret;
  }

};