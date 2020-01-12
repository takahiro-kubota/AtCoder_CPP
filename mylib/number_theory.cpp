ll gcd(ll x, ll y) {
  ll a, b;
  if (y >= x) {
    a = y;
    b = x;
  } else {
    a = x;
    b = y;
  }
  if (b == 0) return a;
  return gcd(a % b, b);
}

ll lcm(ll x, ll y) { return x * y / gcd(x, y); }