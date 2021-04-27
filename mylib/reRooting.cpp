#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

ll const INF = (1LL << 50);

static const long long mod = 1000000007;
// static const long long mod = 998244353;

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
  mint fac(ll n) { return fact[n]; }
  mint invfac(ll n) { return invfact[n]; }
};

using vm = vector<mint>;
using vvm = vector<vm>;

vvll to;
vll nst;
vm dp;

modutils mu(200100);

ll n;

void dfs(ll u, ll p) {
  dp[u] = 1, nst[u] = 0;
  for (auto v : to[u]) {
    if (v == p) continue;
    dfs(v, u);
    dp[u] *= dp[v]*mu.comb(nst[u]+nst[v], nst[v]);
    nst[u] += nst[v];
  }
  nst[u]++;
}

void efs(ll u, ll p) {
  if (p != -1) {
    mint x = dp[p] / (mu.comb(n - 1, nst[u])*dp[u]);
    dp[u] =  x * dp[u] * mu.comb(n - 1, n - nst[u]);
  }
  for (auto v : to[u]) {
    if (v == p) continue;
    efs(v, u);
  }
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  cin >> n;
  to.resize(n);
  rep(_, n - 1) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }

  dp.resize(n);
  nst.resize(n);
  dfs(0, -1);
  //rep(i, n) {dfs(i, -1); cout << dp[i] << endl;}
  efs(0, -1);
  for (auto ans : dp) cout << ans << endl;

  return 0;
}


///// left - right ver
void dfs(ll u, ll p) {
  dp[u] = 1;
  for (auto v : to[u]) {
    if (v == p) continue;
    dfs(v, u);
    dp[u] *= dp[v]+1;
  }
}

void efs(ll u, mint x, ll p) {
  if (p != -1) {
    dp[u] *=  x + 1;
  }

  ll nc = to[u].size();
  vm cml(nc+1, 1), cmr(nc+1, 1);
  rep(i, nc) {
    ll vi = to[u][i];
    ll j = nc - 1 - i;
    ll vj = to[u][j];
    mint di = (vi == p) ? x : dp[vi];
    cml[i+1] = (di+1)*cml[i];
    mint dj = (vj == p) ? x : dp[vj];
    cmr[j] = (dj+1)*cmr[j+1];
  }

  rep(i, nc){
    ll vi = to[u][i];
    if (vi == p) continue;
    mint ux = cml[i]*cmr[i+1];
    efs(vi, ux, u);
  }
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n;
  cin >> n >> mod;
  to.resize(n);
  rep(_, n - 1) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }

  dp.resize(n);
  dfs(0, -1);
  //rep(i, n) {dfs(i, -1); cout << dp[i] << endl;}
  
  efs(0, -1, -1);
  for(mint ans : dp) cout << ans << endl;

  return 0;
}
