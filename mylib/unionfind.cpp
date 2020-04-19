// Union-Find木
// 初期化 UF(N); Nは要素数
// 結合 unite(x,y); 同じ集合か判定 same(x,y);
// 集合の数 count
struct UnionFind {
  vector<ll> par, sizes;
  ll cnt;
  UnionFind(ll N) : par(N), sizes(N, 1), cnt(N) {
    for (ll i = 0; i < N; i++) par[i] = i;
  }

  ll find(ll x) { return par[x] == x ? x : par[x] = find(par[x]); }

  bool same(ll x, ll y) { return find(x) == find(y); }

  ll size(ll x) { return sizes[find(x)]; }

  void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sizes[x] < sizes[y]) swap(x, y);
    par[y] = x;
    sizes[x] += sizes[y];
    cnt--;
  }

  ll count() const { return cnt; }
};