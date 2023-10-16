P nml(ll _a, ll _b){
  ll a, b;
  if(_b == 0) {
    return P(1, 0);
  } else if(_b < 0){
    a = -_a, b = -_b;
  }
  ll g = __gcd(_a, _b);
  a = _a/g, b = _b/g;
  return P(a, b);
}

// returns "x > y". can be used as the comparison func. for sort.
bool cmp(P x, P y){
  return (x.first*y.second > x.second*y.first);
}