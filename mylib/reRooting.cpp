// ver2. struct
struct Rerooting {
  struct DP {
    ll x;
    DP(ll x=0):x(x) {}
    DP operator+(const DP& a) const {
      // edit here
      //return DP(x|a.x);
    }
    DP getNodeVal() const {
      // edit here
      //return DP(!x);
    }
  };
  
  ll n;
  vvll to;
  vector<vector<DP>> dp;
  vector<DP> ans;
  Rerooting(ll n=0):n(n),to(n),dp(n),ans(n) {}
  void addEdge(ll a, ll b) {
    to[a].push_back(b);
    to[b].push_back(a);
  }
  void init() {
    dfs(0);
    bfs(0);
  }

  DP dfs(ll v, ll p=-1) {
    DP dpSum;
    ll nc = to[v].size();
    dp[v] = vector<DP>(nc);
    rep(i, nc) {
      int u = to[v][i];
      if (u == p) continue;
      dp[v][i] = dfs(u,v);
      dpSum = dpSum + dp[v][i];
    }
    return dpSum.getNodeVal();
  }

  void bfs(ll v, const DP& dpP=DP(), ll p=-1) {
    ll nc = to[v].size();
    rep(i, nc) if (to[v][i] == p) dp[v][i] = dpP;

    vector<DP> cumL(nc+1);
    rep(i, nc) cumL[i+1] = cumL[i] + dp[v][i];
    vector<DP> cumR(nc+1);
    rrepE(i, nc-1, 0) cumR[i] = cumR[i+1] + dp[v][i];
    ans[v] = cumL[nc].getNodeVal();

    rep(i, nc) {
      int u = to[v][i];
      if (u == p) continue;
      DP d = cumL[i] + cumR[i+1];
      bfs(u, d.getNodeVal(), v);
    }
  }
};

// ver2. write in main body
int main(){
  cout << fixed << setprecision(15);
  
  ll n;
  cin >> n;
  
  vvP to(n);
  rep(i, n-1){
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    to[a].emplace_back(b, c);
    to[b].emplace_back(a, c);
  }

  vll ds(n);
  rep(i, n) cin >> ds[i];

  vll dp(n, 0);
  auto f = [&](auto f, ll u, ll p) -> void {
    for(auto [v, c] : to[u]){
      if(v == p) continue;
      f(f, v, u);
      chmax(dp[u], dp[v]+c);
      chmax(dp[u], ds[v]+c);
    }
  };
  f(f, 0, -1);
  debug(dp);

  vll ep(n, 0);
  auto g = [&](auto g, ll u, ll p, ll x) -> void {
    // pre proc.
    ll nv = to[u].size();
    for(auto [v, c] : to[u]) if(v==p) dp[v] = x;
    vll cl(nv+1, 0), cr(nv+1, 0);
    rep(i, nv) {
      auto [vi, ci] = to[u][i];
      cl[i+1] = max({cl[i], dp[vi]+ci, ds[vi]+ci});
    }
    rrepE(i, nv-1, 0) {
      auto [vi, ci] = to[u][i];
      cr[i] = max({cr[i+1], dp[vi]+ci, ds[vi]+ci});
    }

    // my val
    ep[u] = cl[nv];

    // dfs rec
    rep(i, nv){
      auto [v, c] = to[u][i];
      if(v == p) continue;
      ll xv = max(cl[i], cr[i+1]);
      g(g, v, u, xv);
    }
  };

  g(g, 0, -1, 0);

  rep(i, n) cout << ep[i] << endl;
  
	return 0;
}