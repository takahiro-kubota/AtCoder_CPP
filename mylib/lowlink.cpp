// sample code for ABC334G
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
#include <unordered_set>
#include <vector>
#include <random>
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
using vvvvll = vector<vvvll>;
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
constexpr ll INF = (1LL << 60);
//constexpr ld eps = 1E-10;
//constexpr ll mod = 1000000007;
constexpr ll mod = 998244353;
//ll mod;
ll xadd(ll a, ll b) { return a+b; }
ll xmax(ll a, ll b) { return max(a, b); }
ll xmin(ll a, ll b) { return min(a, b); }
ll xinf() { return INF; }
ll xminf() { return -INF; }
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

ld ld_dist(ld x, ld y, ld a, ld b){
  return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

ll mymod(ll a, ll b) { return (a%b+b)%b; }

struct Lowlink {
  ll n;
  vvll to;
  vll ord, low;
  vll rs; // roots
  vvll to_dfs_tree;
  Lowlink(ll _n, const vvll& _to){
    n = _n;
    to = _to;
    to_dfs_tree.assign(n, vll());
    assert(to.size()==n);
    ord.assign(n, -1);
    low.assign(n, -1);
    init();
  }

  // set: rs, ord, low, to_dfs_tree
  void init(){
    rep(r, n) if(ord[r]==-1) {
      rs.push_back(r);
      auto f = [&](auto f, ll u, ll& t) -> ll {
        ord[u] = t++;
        low[u] = ord[u];
        for(ll v : to[u]) {
          if(ord[v]==-1){
            chmin(low[u], f(f, v, t));
            to_dfs_tree[u].push_back(v);
          } else {
            chmin(low[u], ord[v]);
          }
        }
        return low[u];
      };
      ll t = 0;
      f(f, r, t);
    }
  }

  // unique to ABC334Ga
  mint solve(){
    mint ans = 0;
    auto g = [&](auto g, ll u, ll p) -> void {
      ll c = 0;
      for(ll v : to_dfs_tree[u]) if(p != v) {
        c += low[v] >= ord[u];
        g(g, v, u);
      }
      ans += rs.size()-1 + c + (p!=-1);
    };
    for(ll r : rs) g(g, r, -1);
    ans /= n;
    return ans;
  }

};

int main(){
  cout << fixed << setprecision(15);

  ll h, w;
  cin >> h >> w;

  vector<string> mp(h);
  map<P, ll> id;
  rep(i, h) {
    cin >> mp[i];
    rep(j, w) if(mp[i][j]=='#') id[P(i, j)] = id.size();
  }

  ll n = id.size();
  vvll to(n);
  rep(i, h) rep(j, w) if(mp[i][j]=='#'){
    ll u = id[P(i, j)];
    rep(d, 4){
      ll ni = i + dx[d], nj = j + dy[d];
      bool rng = 0 <= ni && ni < h && 0 <= nj && nj < w && mp[ni][nj]=='#';
      if(!rng) continue;
      assert(id.count(P(ni, nj)));
      ll v = id[P(ni, nj)];
      to[u].push_back(v);
    }
  }

  // low link
  Lowlink llk(n, to);
  mint ans = llk.solve();
  cout << ans << endl;

  return 0;
}
