{  // compress x
  map<ll, ll> mp;
  rep(i, n) mp[xs[i]] = 0, mp[xxs[i]] = 0;
  ll j = 0;
  for (auto& x : mp) x.second = j++;
  rep(i, n) xs[i] = mp[xs[i]], xxs[i] = mp[xxs[i]];
}