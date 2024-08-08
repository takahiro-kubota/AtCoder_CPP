  priority_queue<P, vP, greater<P>> q;
  vll dp(n, INF);
  dp[0] = 0;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();
    if (dp[u] < du) continue;
    for (auto [v, c] : to[u]) {
      if (chmin(dp[v], du + c)) {
        q.emplace(dp[v], v);
      }
    }
  }