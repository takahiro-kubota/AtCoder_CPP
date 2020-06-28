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
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

static const long long mod = 1000000007;

ll n, h = 20;
vvll to, par;
vll dep;

void dfs(ll x, ll p, ll d) {
  par[0][x] = p;
  dep[x] = d;
  for (auto& y : to[x])
    if (y != p) dfs(y, x, d + 1);
}

void build() {
  dep.resize(n);
  par.assign(h, vll(n, -1));
  dfs(0, -1, 0);
  rep(i, h - 1) {
    rep(j, n) {
      if (par[i][j] < 0)
        par[i + 1][j] = -1;
      else
        par[i + 1][j] = par[i][par[i][j]];
    }  // j
  }    // i
}

ll lca(ll u, ll v) {
  if (dep[u] > dep[v]) swap(u, v);
  rep(i, h) if ((dep[v] - dep[u]) >> i & 1) v = par[i][v];
  assert(dep[v] == dep[u]);
  if (u == v) return u;
  for (ll i = h - 1; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }  // i
  return par[0][u];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  cin >> n;
  to.resize(n);

  rep(i, n - 1) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }

  build();

  ll q;
  cin >> q;
  rep(i, q) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    ll ans = dep[u] + dep[v] - 2 * dep[lca(u, v)] + 1;
    cout << ans << endl;
  }

  return 0;
}
