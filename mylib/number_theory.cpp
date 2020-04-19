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

// prime factorization
map<ll, ll> prime_factor(ll n) {
  map<ll, ll> ret;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1) ret[n] = 1;
  return ret;
}