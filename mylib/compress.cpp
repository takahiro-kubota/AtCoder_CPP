pair<vll, vll> compress(const vll& as){
  ll n = as.size();
  map<ll, ll> mp;
  ll j = 0;
  for(auto  a : as) mp[a] = 0;
  vll rv(n);
  for(auto& [k, v] : mp) {
    v = j;
    rv[j] = v;
    j++;
  }
  vll cs(n);
  rep(i, n) {
    cs[i] = mp[as[i]];
  }
  return make_pair(cs, rv);
}