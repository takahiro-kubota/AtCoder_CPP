  vvll to(n);
  rep(i, n-1){
    ll a, b;
    cin >> a >> b;
    a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  auto f = [&](auto f, ll u, ll p) -> P {
    P ret = {0, u}; // {dist from u, node idx}
    for(ll v : to[u]){
      if(v == p) continue;
      chmax(ret, f(f, v, u));
    }
    auto [dist, node] = ret;
    return P(dist+1, node);
  };

  auto [da, a] = f(f, 0, -1);
  auto [db, b] = f(f, a, -1);