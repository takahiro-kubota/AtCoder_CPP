struct LzyST {
  ll n;
  vll dat, laz;
  const ll ival = ((1LL << 31) - 1);
  LzyST() {}
  LzyST(ll n_) { init(n_); }
  void init(ll n_) {
    n = 1;
    while (n < n_) n *= 2;
    dat.clear();
    dat.resize(2 * n - 1, ival);
    laz.clear();
    laz.resize(2 * n - 1, -1);
  }
  inline void eval(ll len, ll k) {
    if (laz[k] < 0) return;
    if (k * 2 + 1 < n * 2 - 1) {
      laz[k * 2 + 1] = laz[k];
      laz[k * 2 + 2] = laz[k];
    }
    dat[k] = laz[k];
    laz[k] = -1;
  }
  ll update(ll a, ll b, ll x, ll k, ll l, ll r) {
    eval(r - l, k);
    if (r <= a || b <= l) return dat[k];
    if (a <= l && r <= b) return laz[k] = x;
    eval(r - l, k);
    dat[k] = min(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
                 update(a, b, x, k * 2 + 2, (l + r) / 2, r));
    return dat[k];
  }
  ll query(ll a, ll b, ll k, ll l, ll r) {
    eval(r - l, k);
    if (r <= a || b <= l) return ival;
    if (a <= l && r <= b) return dat[k];
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
  void update(ll a, ll b, ll x) { update(a, b + 1, x, 0, 0, n); }
  ll query(ll a, ll b) { return query(a, b + 1, 0, 0, n); }
};

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, q;
  cin >> n >> q;
  LzyST lst(n);
  for (ll i = 0; i < q; i++) {
    ll f;
    cin >> f;
    if (!f) {
      ll s, t, x;
      cin >> s >> t >> x;
      lst.update(s, t, x);
    } else {
      ll s, t;
      cin >> s >> t;
      cout << lst.query(s, t) << endl;
    }
  }

  return 0;
}
