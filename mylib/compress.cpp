// compress and destroy as
void za(vll &as){
  set<ll> s(a.begin(),a.end());
  map<ll, ll> mp;
  ll j = 0;
  for(auto  x : s) mp[x] = j++;
  for(auto& x : a) x = mp[x];
}
