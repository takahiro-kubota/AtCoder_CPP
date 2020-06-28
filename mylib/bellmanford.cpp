void dfs(vvll& to, vector<bool>& rblFrom1, ll v) {
  if (rblFrom1[v]) return;
  rblFrom1[v] = true;
  for (auto u : to[v]) {
    dfs(to, rblFrom1, u);
  }
}

void rdfs(vvll& ot, vector<bool>& rblToN, ll v) {
  if (rblToN[v]) return;
  rblToN[v] = true;
  for (auto u : ot[v]) {
    rdfs(ot, rblToN, u);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, m;
  cin >> n >> m;

  vector<bool> rblFrom1(n, false);
  vector<bool> rblToN(n, false);
  vvll to(n);
  vvll ot(n);

  vT eds(m);
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    c = -c;
    eds[i] = T(a, b, c);
    to[a].push_back(b);
    ot[b].push_back(a);
  }

  dfs(to, rblFrom1, 0);
  rdfs(ot, rblToN, n - 1);

  vector<bool> ok(n);
  rep(i, n) ok[i] = rblFrom1[i] && rblToN[i];

  vll d(n, INF);
  d[0] = 0;
  bool upd = true;
  ll step = 0;
  while (upd) {
    upd = false;
    for (auto e : eds) {
      ll a, b, c;
      tie(a, b, c) = e;
      if (!ok[a]) continue;
      if (!ok[b]) continue;
      ll newD = d[a] + c;
      if (newD < d[b]) {
        d[b] = newD;
        upd = true;
      }
    }
    step++;
    if (step > n) {
      puts("inf");
      return 0;
    }
  }

  ll ans = -d[n - 1];
  cout << ans << endl;

  return 0;
}
