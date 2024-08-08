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