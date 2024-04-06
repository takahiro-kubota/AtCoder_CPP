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


struct Trie {
  ll n;
  vector<map<char, ll>> to;
  vll cnt, anc, des;

  Trie(){
    n = 0;
    add_new_node();
  }

  void add_new_node(){
    to.push_back(map<char, ll>());
    cnt.push_back(0);
    anc.push_back(0);
    des.push_back(0);
    n++;
  }

  ll add(const string& s) {
    ll u = 0;
    for (char c : s) {
      if (!to[u].count(c)) {
        to[u][c] = n;
        add_new_node();
      }
      u = to[u][c];
    }
    cnt[u]++;
    return u;
  }

  void dfs(ll u, ll d){
    anc[u] = d;
    for(auto [c, v] : to[u]){
      dfs(v, d+cnt[u]);
      des[u] += des[v]+cnt[v];
    }
  }
};

// sample code ABC268G AC code
int main(){
  cout << fixed << setprecision(15);

  ll n;
  cin >> n;

  Trie tr;

  vll itou(n);
  rep(i, n){
    string s;
    cin >> s;
    itou[i] = tr.add(s);
  }

  tr.dfs(0, 0);

  rep(i, n){
    ll u = itou[i];
    ll na = tr.anc[u];
    ll nd = tr.des[u];
    mint ans = mint(na+1) + mint(n-na-1-nd)/2;
    cout << ans << endl;
  }

	return 0;
}
