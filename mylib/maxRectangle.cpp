// asのの最大長方形を求める
ll f(vll& as){
  as.push_back(0);
  ll n = as.size();
  stack<P> st;
  ll ret = 0;
  rep(r, n){
    ll nl = r;
    while(!st.empty() && st.top().second >= as[r]){
      auto [l, al] = st.top();
      st.pop();
      chmax(ret, (r-l)*al);
      nl = l;
    }
    st.emplace(nl, as[r]);
    
  }
  as.pop_back();
  return ret;
}

// 短冊の幅x, 高さyのパターン
// y = [5, 2, 4]
// x = [2, 3, 6]
ll f(vll& ys, vll& dxs){
  assert(ys.size()==dxs.size());
  ys.push_back(0), dxs.push_back(0);
  ll n = ys.size();
  ll ret = 0;
  stack<P> st;
  ll r = 0;
  rep(i, n){
    ll nl = r;
    while(!st.empty() && st.top().second >= ys[i]){
      auto [l, y] = st.top();
      st.pop();
      chmax(ret, y*(r-l));
      nl = l;
    }
    r += dxs[i];
    st.emplace(nl, ys[i]);
  }
  ys.pop_back(), dxs.pop_back();
  return ret;
}

// x 座標で与えるパターン
// y =   [5, 2, 4]
// x = [0, 2, 5, 11]
ll f(vll& ys, vll& xs){
  assert(ys.size()+1==xs.size());
  ys.push_back(0), xs.push_back(xs.back());
  ll n = ys.size();
  ll ret = 0;
  stack<P> st;
  rep(i, n){
    ll nl = xs[i];
    while(!st.empty() && st.top().second >= ys[i]){
      auto [l, y] = st.top();
      st.pop();
      chmax(ret, y*(xs[i]-l));
      nl = l;
    }
    st.emplace(nl, ys[i]);
  }
  ys.pop_back(), xs.pop_back();
  return ret;
}