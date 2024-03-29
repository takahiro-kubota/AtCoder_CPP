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
  Reverse(ans);

  for(ll x : ans) cout << x << " ";

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

  vll seen(n, 0);
  vll ans;
  auto f = [&](auto f, ll u) -> void{
    for(ll v : to[u]){
      if(seen[v]) continue;
      seen[v] = 1;
      f(f, v);
    }
    ans.push_back(u);
  };

  rep(i, n) if(!seen[i]) {
    seen[i] = 1;
    f(f,i);
  }

  Reverse(ans);
  for(ll x : ans) cout << x << ' ';

	return 0;
}