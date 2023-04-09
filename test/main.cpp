#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, y) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), y))
#define Upper_bound(v, y) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), y))
#define __bpc __builtin_popcount
#define __bpcll __builtin_popcountll

#ifdef LOCAL
#  include <debug_print.hpp>
#  define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#  define debug(...) (static_cast<void>(0))
#endif

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vP = vector<P>;
using vvP = vector<vector<P>>;
using vT = vector<T>;
using vvT = vector<vT>;
using vD = vector<double>;
using vvD = vector<vD>;
using vvvD = vector<vvD>;

using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

/* Macros reg. ends here */

constexpr ll INF = (1LL << 50);
constexpr double eps = 1E-10;

constexpr ll mod = 1000000007;
//constexpr ll mod = 998244353;
//ll mod;

struct mint {
  ll x;  // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

class modutils {
  vector<mint> fact, invfact;

 public:
  modutils(int n = 200005) : fact(n + 1), invfact(n + 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    invfact[n] = fact[n].inv();
    for (int i = n; i >= 1; i--) invfact[i - 1] = invfact[i] * i;
  }
  mint pow(mint x, ll n) { return x.pow(n); }
  mint comb(ll n, ll k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * invfact[k] * invfact[n - k];
  }
  mint perm(ll n, ll k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * invfact[n - k];
  }
  mint hom(ll n, ll k) { return comb(n + k - 1, k); }

  mint fac(ll n) { return fact[n]; }
  mint invfac(ll n) { return invfact[n]; }
};

using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

ll mn(ll x, ll y) {return min(x, y);}
ll e() {return INF;}

int main() {
  cout << fixed << setprecision(15);

  ll n, m;
  cin >> n >> m;

  vll as(n);
  rep(i, n) cin >> as[i];
  segtree<ll, mn, e> st(n);
  rep(i, n) {
    ll c; cin >> c;
    st.set(i, c);
  }
  vll mst(n, 0);
  rep(i, m) {
    ll x; cin >> x;
    x--;
    mst[x] = 1;
  }

  vvll dp(n+1, vll(n+1, INF));
  dp[0][0] = 0;

  rep(i, n){
    rep(j, n){
      if(dp[i][j] == INF) continue;
      if(!mst[i]) chmin(dp[i+1][j], dp[i][j]);
      ll mnv = st.prod(i-j, i+1);
      ll add = as[i] + mnv;
      chmin(dp[i+1][j+1], dp[i][j] + add);
    }
  }

  ll ans = INF;
  rep(j, n+1) chmin(ans, dp[n][j]);
  cout << ans << endl;
  
  return 0;
}
