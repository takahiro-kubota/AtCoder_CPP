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

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll h, w;
  cin >> h >> w;

  vector<string> mp(h);
  rep(i, h) cin >> mp[i];

  ll const MX = 1 << 18;

  set<P> seen;
  vector<map<ll, ll>> f(MX);
  vvll invf(MX);
  f[0][0] = 0;
  invf[0].push_back(0);
  queue<P> q;
  q.emplace(0, 0);
  seen.emplace(0, 0);
  // u : 
  //  - (w+1)-bit string which expresses last w+1 grid's state.
  //    - 1 ... king is placed
  //    - 0 ... king is not placed
  //  - u is at most 25 bit (24x24x(1<<25) space is MLE) but the number of u's possible values is <= 2^18
  // f[j][u] : 
  //  - id of the bit pattern u (in [0..2^18-1]) when the col. position is j.
  //    - the set of ids are managed FOR EACH j (otherwise, the max. id > 2^18 orz)
  // nks[j][f[j][u]] : 
  //  - the vector (list) of ids that can be reached from the state (j, u)
  //  - if x is in nks[j][f[j][u]], the state transition (j, u) -> (nj, v) is possible where nj = (j + 1)%w, and v = inv(f[nj][x])
  vvvll nks(w, vvll(MX, vll()));
  while (q.size()) {
    auto [j, u] = q.front();
    q.pop();
    rep(b, 2) { // j ni king wo okuka-douka. b==1 : oku, b==0 : okanai.
      bool ok = true;
      ll nj = (j + 1) % w;
      if (nj != 0) {
        ok &= !(u & 1);        // hidari ni king ga attara dame. (b==0 no tokiha atode mask sareru node kankei nai.)
        ok &= !((u >> w) & 1); // hidari ue ni (ry
      }
      ok &= !((u >> (w - 1)) & 1); // ue
      if (nj != w - 1) ok &= !((u >> (w - 2)) & 1); // migi ue
      ok |= b == 0;
      if (!ok) continue;
      ll v = (((u << 1) & ((1 << (w + 1)) - 1))) + b; // next state
      if(!f[nj].count(v)) {
        ll fv = f[nj].size(); 
        f[nj][v] = fv;
        assert((ll)invf[nj].size() == fv);
        invf[nj].push_back(v);
      }
      nks[j][f[j][u]].push_back(f[nj][v]);
      if(seen.count({nj, v})) continue;
      q.emplace(nj, v);
      seen.emplace(nj, v);
    }
  }

  vll cnt(MX, 0);
  rep(j, MX) cnt[j] = f[j].size();

  vvvm dp(h, vvm(w, vm(MX, 0)));
  dp[0][0][f[0][0]] = 1;
  if (mp[0][0] == '.') dp[0][0][f[0][1]] = 1;
  rep(i, h) rep(j, w) {
    if (i == h - 1 && j == w - 1) break;
    ll ni = i + ((j + 1) / w);
    ll nj = (j + 1) % w;
    rep(k, cnt[j]) {
      //printf("%lld, %lld, %lld: %lld\n", i, j, invf[k], dp[i][j][k].x);
      for(ll nk : nks[j][k]) if(!(invf[nj][nk]&1) || mp[ni][nj] == '.') { dp[ni][nj][nk] += dp[i][j][k]; }
    }
  }

  mint ans = 0;
  for (auto cnt : dp[h - 1][w - 1]) {
    ans += cnt;
  }

  cout << ans << endl;

  return 0;
}
