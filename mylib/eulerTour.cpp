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
#define repE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Uniq(v) Sort(v), v.erase(unique(v.begin(), v.end()), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, y) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), y))
#define Upper_bound(v, y) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), y))
#define __bpcll __builtin_popcountll
#define sz(x) (ll)x.size()

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

using ll = long long;
using l3 = __int128_t;
using ull = unsigned long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vP = vector<P>;
using vvP = vector<vector<P>>;
using vT = vector<T>;
using vvT = vector<vT>;
using vD = vector<ld>;
using vvD = vector<vD>;
using vvvD = vector<vvD>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

constexpr ll INF = (1LL << 50);
constexpr double eps = 1E-10;

//constexpr ll mod = 1000000007;
constexpr ll mod = 998244353;
//ll mod;

ll xadd(ll a, ll b) { return a+b; }
ll xmax(ll a, ll b) { return max(a, b); }
ll xmin(ll a, ll b) { return min(a, b); }
ll xinf() { return INF; }
ll xzero() { return 0LL; }

struct mint
{
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

class modutils
{
  vector<mint> fact, invfact;

public:
  modutils(int n = 200005) : fact(n + 1), invfact(n + 1)
  {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
      fact[i] = fact[i - 1] * i;
    invfact[n] = fact[n].inv();
    for (int i = n; i >= 1; i--)
      invfact[i - 1] = invfact[i] * i;
  }
  mint pow(mint x, ll n) { return x.pow(n); }
  mint comb(ll n, ll k)
  {
    if (n < 0 || k < 0 || n < k)
      return 0;
    return fact[n] * invfact[k] * invfact[n - k];
  }
  mint perm(ll n, ll k)
  {
    if (n < 0 || k < 0 || n < k)
      return 0;
    return fact[n] * invfact[n - k];
  }
  mint hom(ll n, ll k) { return comb(n + k - 1, k); }

  mint fac(ll n) { return fact[n]; }
  mint invfac(ll n) { return invfact[n]; }
};

using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

struct eulerTour {
  // parameters
  ll n;
  vvT to;
  
  // varialbles used internally
  vll tin, tout, i2v, t2e, t2v;
  segtree<ll, xadd, xzero> st_ewt;
  segtree<ll, xmin, xinf> st_in_v;
  ll tmx, t;

  // the constructor and related functions
  eulerTour(ll _n, vvT _to){
    n = _n;
    to = _to;
    tmx = 2*n, t = 0;
    tin.resize(n+1), tout.resize(n+1);
    i2v.resize(n+1), t2e.resize(tmx), t2v.resize(tmx);
    st_ewt = segtree<ll, xadd, xzero>(tmx);
    build(1, 0, 0, 1);
    st_in_v = segtree<ll, xmin, xinf>(tmx);
    rep(i, tmx) st_in_v.set(i, tin[t2v[i]]);
  }

  void build(ll u, ll p, ll w, ll i){
    // p -> u
    tin[u] = t;
    i2v[i] = u;
    t2e[t] = u, st_ewt.set(t, w);
    t2v[t] = u;
    t++;

    // recursion
    for(auto [v, w_uv, i_uv] : to[u]){
      if(v == p) continue;
      build(v, u, w_uv, i_uv);
    }

    // u -> p
    tout[u] = t;
    t2e[t] = -u, st_ewt.set(t, -w);
    t2v[t] = p;
    t++;
  }

  /*                      */
  /* -- useful methods -- */
  /*                      */

  // returns lca of u and v
  ll lca(ll u, ll v){
    ll l = tin[u], r = tin[v];
    if(l > r) swap(l, r);
    return t2e[st_in_v.prod(l, r+1)];
  };

  // e: idx of an edge as input
  void changeWeight(ll e, ll w){
    ll v = i2v[e];
    st_ewt.set(tin[v], w);
    st_ewt.set(tout[v], -w);
  }

  // returns the weight of the path from u to v (= from v to u);
  ll getPathWeight(ll u, ll v){
    ll c = lca(u, v);
    ll ans = st_ewt.prod(tin[c]+1, tin[u]+1);
    ans += st_ewt.prod(tin[c]+1, tin[v]+1);
    return ans;
  }
};

// sample code ABC294G
int main(){
  cout << fixed << setprecision(15);

  ll n;
  cin >> n;

  vvT to(n+1);
  repE(i, 1, n-1){
    ll u, v, w;
    cin >> u >> v >> w;
    to[u].emplace_back(v, w, i);
    to[v].emplace_back(u, w, i);
  }

  eulerTour et(n, to);

  ll q; 
  cin >> q;
  rep(_, q){
    ll t, a, b; 
    cin >> t >> a >> b;
    if(t == 1){
      et.changeWeight(a, b);
    } else {
      cout << et.getPathWeight(a, b) << endl;
    }
  }

  return 0;
}