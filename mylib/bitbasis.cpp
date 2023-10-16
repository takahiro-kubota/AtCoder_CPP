struct bitbasis {
  ll n; // n bit vector
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