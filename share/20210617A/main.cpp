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
#define __bpc __builtin_popcount
#define __bpcll __builtin_popcountll

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
  mint hom(ll n, ll k) { return comb(n + k - 1, k); }

  mint fac(ll n) { return fact[n]; }
  mint invfac(ll n) { return invfact[n]; }
};

using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

#include <unordered_set>
vector<map<int, int>> f;
vvi invf;
vvvi nks;
unordered_set<ll> seen;
ll w;
void bfs(int u, int j) {
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  while (q.size()) {
    auto [u, j] = q.front();
    q.pop();
    rep(b, 2) {
      bool ok = true;
      ll nj = (j + 1) % w;
      if (nj != 0) {
        ok &= !(u & 1);
        ok &= !((u >> w) & 1);
      }
      ok &= !((u >> (w - 1)) & 1);
      if (nj != w - 1) ok &= !((u >> (w - 2)) & 1);
      ok |= b == 0;
      if (!ok) continue;
      ll v = (((u << 1) & ((1 << (w + 1)) - 1))) + b;
      if (!f[nj].count(v)) {
        ll fv = f[nj].size();
        f[nj][v] = fv;
        assert((ll)invf[nj].size() == fv);
        invf[nj].push_back(v);
      }
      nks[j][f[j][u]].push_back(f[nj][v]);
      ll key = (((ll)nj) << 32) | v;
      if (seen.count(key)) continue;
      seen.emplace(key);
      q.emplace(v, nj);
    }
  }
}

void dfs(int u, int j) {
  rep(b, 2) {
    bool ok = true;
    int nj = (j + 1) % w;
    if (nj != 0) {
      ok &= !(u & 1);
      ok &= !((u >> w) & 1);
    }
    ok &= !((u >> (w - 1)) & 1);
    if (nj != w - 1) ok &= !((u >> (w - 2)) & 1);
    ok |= b == 0;
    if (!ok) continue;
    int v = (((u << 1) & ((1 << (w + 1)) - 1))) + b;
    if (!f[nj].count(v)) {
      int fv = f[nj].size();
      f[nj][v] = fv;
      assert((ll)invf[nj].size() == fv);
      invf[nj].push_back(v);
    }
    nks[j][f[j][u]].push_back(f[nj][v]);
    ll key = (((ll)nj) << 32) | v;
    if (seen.count(key)) continue;
    seen.emplace(key);
    dfs(v, nj);
  }
}

#include <sys/time.h>
struct timeval itv, tv;
void tick_init() { gettimeofday(&itv, NULL); }
void tick(string s) {
  gettimeofday(&tv, NULL);
  double x =
      double((tv.tv_sec - itv.tv_sec) * 1000000 + tv.tv_usec - itv.tv_usec) /
      1000000;
  printf("%s: %3.3f\n", s.c_str(), x);
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  int h;
  cin >> h >> w;

  vector<string> mp(h);
  rep(i, h) cin >> mp[i];

  int const MX = 1 << 18;

  tick_init();

  f.assign(MX, map<int, int>());
  invf.assign(MX, vi());
  f[0][0] = 0;
  invf[0].push_back(0);
  nks.assign(w, vvi(MX, vi()));
  seen.emplace(0);
  //dfs(0, 0);
  //tick("after dfs");

  bfs(0, 0);
  tick("after bfs");

  vi cnt(MX, 0);
  rep(j, MX) cnt[j] = f[j].size();

  vvvm dp(h, vvm(w, vm(MX, 0)));
  dp[0][0][f[0][0]] = 1;
  if (mp[0][0] == '.') dp[0][0][f[0][1]] = 1;
  ll step_cnt = 0;
  rep(i, h) rep(j, w) {
    if (i == h - 1 && j == w - 1) break;
    int ni = i + ((j + 1) / w);
    int nj = (j + 1) % w;
    rep(k, cnt[j]) {
      // printf("%lld, %lld, %lld: %lld\n", i, j, invf[k], dp[i][j][k].x);
      for (int nk : nks[j][k]){
        if (!(invf[nj][nk] & 1) || mp[ni][nj] == '.') {
          dp[ni][nj][nk] += dp[i][j][k];
        }
        step_cnt++;
      }
    }
    printf("i=%lld, j=%lld", i, j);
    tick("");
  }
  printf("step: %lld\n", step_cnt);

  tick("after dp ");

  mint ans = 0;
  for (auto cnt : dp[h - 1][w - 1]) {
    ans += cnt;
  }

  cout << ans << endl;

  return 0;
}
