priority_queue<P, vP, greater<P>> pque;
vll dist(n, INF);
dist[0] = 0;
pque.emplace(0, 0);
while (!pque.empty()) {
  auto [du, u] = pque.top();
  pque.pop();
  if (dist[u] < du) continue;
  for (auto [c, v] : to[u]) {
    if (dist[v] > du + c) {
      dist[v] = du + c;
      pque.emplace(du + c, v);
    }
  }
}

auto dks = [&](ll st, vll& dist) {
  priority_queue<P, vP, greater<P>> q;
  q.emplace(0, st);
  dist[st] = 0;
  while (q.size()) {
    auto [du, u] = q.top();
    q.pop();
    if (dist.at(u) < du) continue;
    for (auto [v, co] : to[u]) {
      ll dv = du + co;
      if (chmin(dist[v], dv)) {
        q.emplace(dv, v);
      }
    }
  }
};
