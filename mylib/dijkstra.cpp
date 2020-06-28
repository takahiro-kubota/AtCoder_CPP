priority_queue<P, vP, greater<P>> pque;
vll dist(n, INF);
dist[0] = 0;
pque.push({0, 0});
while (!pque.empty()) {
  P p = pque.top();
  pque.pop();
  ll du, u;
  tie(du, u) = p;
  if (dist[u] < du) continue;
  for (auto e : to[u]) {
    ll c, v;
    tie(c, v) = e;
    if (dist[v] > du + c) {
      dist[v] = du + c;
      pque.push({du + c, v});
    }
  }
}
