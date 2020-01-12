ll keta(ll x) {
  ll ret = 1;
  while (x >= 10) {
    x /= 10;
    ret++;
  }
  return ret;
}