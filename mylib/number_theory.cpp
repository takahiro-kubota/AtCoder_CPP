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

ll mynchoosek(ll n, ll r) {
  if (n < r) return 0;
  if (n - r < r) r = n - r;
  ll ret = 1;
  for (ll i = 0; i < r; i++) {
    ret *= (n--);
    ret /= i + 1;
  }
  return ret;
}

ll ipow(ll x, ll t) {
  if (t == 0) return 1;
  ll a = ipow(x, t >> 1);
  a *= a;
  if (t & 1) a *= x;
  return a;
}

vll ds;
for (ll i = 1; i*i <= n; i++){
  if(n % i == 0){
    ds.push_back(i);
    if(n/i != i) ds.push_back(n/i);
  }
}