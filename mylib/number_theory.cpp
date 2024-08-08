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

ll ipow(ll x, ll t) {
  if (t == 0) return 1;
  ll a = ipow(x, t >> 1);
  if(a == INF) return INF;
  a *= a;
  if(a > INF) return INF;
  if (t & 1) {
    a *= x;
    if(a > INF) return INF;
  }
  return a;
}

l3 ipow(ll a, ll x, l3 m){
  l3 ans = 1, ml = a;
  while(x){
    if(x%2) ans = (ans*ml)%m;
    x >>= 1;
    ml = (ml*ml)%m;    
  }
  return ans;
}

vll ds;
for (ll i = 1; i*i <= n; i++){
  if(n % i == 0){
    ds.push_back(i);
    if(n/i != i) ds.push_back(n/i);
  }
}

ll mysqrt(ll n){
  __uint128_t nn = n;
  __uint128_t l = 0, r = 1E19;
  while(l + 1 < r){
    __uint128_t mid = (l + r)/2;
    if(mid*mid <= nn){
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
ll extgcd(ll a, ll b, ll& x, ll& y){
  if(b == 0){
    x = 1, y = 0;
    return a;
  } else {
    ll g = extgcd(b, a%b, y, x);
    y -= (a/b)*x;
    return g;
  }
}

ll cdv(ll x, ll y){
  assert(y != 0);
  if(x == 0) return 0;
  ll ret;
  if((x/(abs(x)))*(y/(abs(y))) == -1){
    ll u = abs(x), v = abs(y);
    ret = u/v*(-1);
  } else {
    ret = (x+y-1)/y;
  }
  return ret;
}

ll fdv(ll x, ll y){
  assert(y != 0);
  if(x == 0) return 0;
  ll ret;
  if((x/(abs(x)))*(y/(abs(y))) == -1){
    ll u = abs(x), v = abs(y);
    ret = (u+v-1)/v*(-1);
  } else {
    ret = x/y;
  }
  return ret;
}

template<class T> T cdv(const T &a, const T &b){
    if(a%b==0){return a/b;}
    if(a>=0){return (a/b)+1;}
    else{return -((-a)/b);}
}
template<class T> T fdv(const T &a, const T &b){
    if(a%b==0){return a/b;}
    if(a>=0){return (a/b);}
    else{return -((-a)/b)-1;}
}