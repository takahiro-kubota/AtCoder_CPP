void rot90_clkwise(vector<string>& a){ // must be recutanglar
  ll h = a.size(), w = a[0].size();
  vector<string> b(w, string(h, '-'));
  rep(i, w) rep(j, h) b.at(i).at(j) = a[h-1-j][i];
  a = b;
}