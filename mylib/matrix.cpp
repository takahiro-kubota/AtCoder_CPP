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
      ret[i][j] = val % mod;
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

// how to use //
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n;
  cin >> n >> mod;

  vvll fmat = {{1, 1}, {1, 0}};
  vvll nmat = matpow(fmat, n - 1);
  ll ans = nmat[1][0] % mod;

  cout << ans << endl;

  return 0;
}