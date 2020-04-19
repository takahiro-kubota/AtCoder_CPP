ll siz;
ll ofst;
vll seg;

void change(ll i, char c) {
  i += ofst;
  seg[i] = 1LL << (c - 'a');
  while (true) {
    i /= 2;
    if (i == 0) break;
    seg[i] = seg[2 * i] | seg[2 * i + 1];
  }
}

ll get(ll l, ll r) {
  ll s = 0;
  l += ofst, r += ofst + 1;
  while (l < r) {
    if (l % 2 == 1) {
      s |= seg[l];
      l++;
    }
    l /= 2;
    if (r % 2 == 1) {
      s |= seg[r - 1];
      r--;
    }
    r /= 2;
  }
  return __builtin_popcount(s);
}

int main() {
  ll n, q;
  string s;
  cin >> n >> s >> q;

  siz = 1;
  while (siz < 2 * n) siz <<= 1;
  ofst = siz >> 1;
  seg.resize(siz, 0);
  rep(i, n) change(i, s[i]);

  rep(i, q) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll i;
      char c;
      cin >> i >> c;
      i--;
      change(i, c);
    } else {
      ll l, r;
      cin >> l >> r;
      l--;
      r--;
      cout << get(l, r) << endl;
    }
  }

  return 0;
}

class Monoid {
 public:
  // 単位元
  ll unit;

  Monoid() {
    // 単位元
    unit = 0;
  }

  // 演算関数
  ll calc(ll a, ll b) { return a + b; }
};

class SegmentTree {
 public:
  // セグメント木の葉の要素数
  ll n;

  // セグメント木
  vector<ll> tree;

  // モノイド
  Monoid mono;

  SegmentTree(vector<ll> &v) {
    n = 1 << (ll)ceil(log2(v.size()));
    tree = vector<ll>(n << 1);
    for (ll i = 0; i < v.size(); i++) {
      update(i, v[i]);
    }
    for (ll i = v.size(); i < n; i++) {
      update(i, mono.unit);
    }
  }

  // k番目の値(0-indexed)をxに変更
  void update(ll k, ll x) {
    k += n;
    tree[k] = x;
    for (k = k >> 1; k > 0; k >>= 1) {
      tree[k] = mono.calc(tree[k << 1 | 0], tree[k << 1 | 1]);
    }
  }

  // [l, r)の最小値(0-indexed)を求める．
  ll query(ll l, ll r) {
    ll res = mono.unit;
    l += n;
    r += n;
    while (l < r) {
      if (l & 1) {
        res = mono.calc(res, tree[l++]);
      }
      if (r & 1) {
        res = mono.calc(res, tree[--r]);
      }
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
  ll operator[](ll k) {
    // st[i]で添字iの要素の値を返す
    if (k - n >= 0 || k < 0) {
      return -INF;
    }
    return tree[tree.size() - n + k];
  }

  void show() {
    ll ret = 2;
    for (ll i = 1; i < 2 * n; i++) {
      cout << tree[i] << " ";
      if (i == ret - 1) {
        cout << endl;
        ret <<= 1;
      }
    }
    cout << endl;
  }
};