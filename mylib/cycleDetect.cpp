// BFS version
int main(){
  cout << fixed << setprecision(15);

  ll n, m;
  cin >> n >> m;

  vvll ot(n);
  vll od(n);
  rep(i, m){
    ll a, b;
    cin >> a >> b;
    ot[b].push_back(a);
    od[a]++;
  }
  rep(i, n) Sort(ot[i]);

  vll ans;

  queue<ll> q;
  rep(i, n) if(!od[i]) ans.push_back(i), q.emplace(i);

  while(!q.empty()){
    ll u = q.front();
    q.pop();
    for(ll v : ot[u]){
      od[v]--;
      if(!od[v]) ans.push_back(v), q.emplace(v);
    }
  }
  cout << (sz(ans)!=n ? "Yes" : "No") << endl;

	return 0;
}

// DFS version
int main(){
  cout << fixed << setprecision(15);

  ll n, m;
  cin >> n >> m;

  vvll to(n);
  rep(i, m){
    ll a, b;
    cin >> a >> b;
    to[a].push_back(b);
  }
  rep(i, n) Sort(to[i]);

  vll ans;
  vll seen(n, 0), fin(n, 0);
  auto f = [&](auto f, ll u) -> void {
    seen[u] = 1;
    fin[u] = 1;
    for(ll v : to[u]){
      if(fin[v]){
        cout << "Yes" << endl;
        exit(0);
      }
      if(seen[v]) continue;
      f(f, v);
    }
    fin[u] = 0;
  };

  rep(i, n) if(!seen[i]) f(f, i);
  cout << "No" << endl;

	return 0;
}