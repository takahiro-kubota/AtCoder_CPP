  ll n;
  cin >> n;

  vvll to(n);
  rep(i, n-1){
    ll u, v;
    cin >> u >> v;
    u--, v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }

  auto f = [&](auto f, ll u, ll p) -> void {
    for(ll v : to[u]) if(v != p) {
      f(f, v, u);
    }
  };
  f(f, 0, -1);