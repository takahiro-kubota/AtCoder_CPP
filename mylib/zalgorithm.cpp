vll myz(string s){
  ll fr = -1, to = -1;
  ll ns = s.size();
  vll z(ns, 0);
  z[0] = ns;
  repE(i, 1, ns-1){
    ll k = 0;
    if(fr != -1) k = min(z[i-fr], to-i);
    if(to-i < 0) k = 0;
    while(i+k < ns && s[i+k] == s[k]) k++;
    z[i] = k;
    if(i+k > to){
      fr = i;
      to = i+k;
    }
  }
  return z;
}