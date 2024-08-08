using vm = vector<mint>;
using vvm = vector<vm>;

vvm matmul(vvm& a, vvm& b) {
  ll xx = a.size();
  ll zz = a[0].size();
  assert(zz == (ll)b.size());
  ll yy = b[0].size();
  vvm ret(xx, vm(yy));

  rep(i, xx) rep(j, yy) {
    mint val = 0;
    rep(k, zz) {
      val += a[i][k] * b[k][j];
      ret[i][j] = val;
    }
  }

  return ret;
}

vvm matpow(vvm& m, ll n) {  // m^n
  ll xx = m.size();
  assert(xx == (ll)m[0].size());
  vvm ret(xx, vm(xx, 0));
  vvm cum = m;
  rep(i, xx) ret[i][i] = 1;
  while (n > 0) {
    if ((n & 1) == 1) ret = matmul(cum, ret);
    if (n == 1) break;
    cum = matmul(cum, cum);
    n >>= 1;
  }
  return ret;
}

// long long
vvll matmul(vvll& a, vvll& b) {
  ll xx = a.size();
  ll zz = a[0].size();
  assert(zz == (ll)b.size());
  ll yy = b[0].size();
  vvll ret(xx, vll(yy));

  rep(i, xx) rep(j, yy) {
    ll val = 0;
    rep(k, zz) {
      val += a[i][k] * b[k][j];
      ret[i][j] = val;
    }
  }

  return ret;
}

vvll matpow(vvll& m, ll n) {  // m^n
  ll xx = m.size();
  assert(xx == (ll)m[0].size());
  vvll ret(xx, vll(xx, 0));
  vvll cum = m;
  rep(i, xx) ret[i][i] = 1;
  while (n > 0) {
    if ((n & 1) == 1) ret = matmul(cum, ret);
    if (n == 1) break;
    cum = matmul(cum, cum);
    n >>= 1;
  }
  return ret;
}