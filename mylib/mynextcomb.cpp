bool my_next_comb(vll& ps, ll midx) {
  ll k = ps.size();
  ll cur = k - 1;
  while (cur >= 0) {
    if (ps[cur] < midx - (k - 1 - cur)) {
      ps[cur]++;
      repE(j, cur + 1, k - 1) { ps[j] = ps[j - 1] + 1; }
      // rep(i, (ll)ps.size()) cout << ps[i] << " ";
      // cout << endl;
      return true;
    }
    cur--;
  }
  return false;
}

// isからm要素を選び並べて得られる配列達を返す
vvll permutations(vll is, ll m){
  // 要高速化？
  vvll ans;
  for(auto js : combinations(is, m)){
    do {
      ans.push_back(js);
    } while(next_permutation(All(js)));
  }
  return ans;
}