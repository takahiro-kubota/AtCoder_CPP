// 木の直径d, 端点a, b, 中心c1, c2として T(d, a, b, c1, c2) を返す.
// (d%2==0ならc1==c2)
tuple<ll, ll, ll, ll, ll> tree_diameter(const vvll& to){
  // 点uからの最遠点vと, u,vのパス長xとしてP(x, v)を返す
  auto f = [&](auto f, ll u, ll p) -> P {
    P ret = {0, u};
    for(ll v : to[u]){
      if(v == p) continue;
      auto [dv, idx] = f(f, v, u);
      chmax(ret, P(dv+1, idx));
    }
    return ret;
  };

  // sからtへのパス上の点リスト(s, tを含む)を返す
  auto g = [&](ll s, ll t) -> vll {
    auto h = [&](auto h, ll u, ll t, ll p, vll& ret) -> bool {
      ret.push_back(u);
      if(u==t) return true;
      for(ll v : to[u]) if(v != p){
        bool rh = h(h, v, t, u, ret);
        if(rh) return true;
      }
      ret.pop_back();
      return false;
    };
    vll lst;
    h(h, s, t, -1, lst);
    return lst;
  };

  f(f, 0, -1);
  auto [da, a] = f(f, 0, -1);
  auto [db, b] = f(f, a, -1);

  vll lst = g(a, b);
  ll nl = lst.size();
  ll c1 = lst[(nl-1)/2];
  ll c2 = lst[nl/2];

  assert(db%2!=0 || c1==c2);
  return tuple<ll, ll, ll, ll, ll>(db, a, b, c1, c2);
} 
 
// ベタ書き版
  vvP to(n);
  rep(i, n-1){
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    to[a].emplace_back(b, c);
    to[b].emplace_back(a, c);
  }

  auto f = [&](auto f, ll u, ll p) -> P {
    P ret = {0, u}; // {dist from u, node idx}
    for(auto [v, c] : to[u]){
      if(v == p) continue;
      auto [dv, idx] = f(f, v, u);
      chmax(ret, P(dv+c, idx));
    }
    return ret;
  };

  auto [da, a] = f(f, 0, -1);
  auto [db, b] = f(f, a, -1);