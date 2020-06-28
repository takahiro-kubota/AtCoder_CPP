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

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
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

struct edge {
  ll to, cap, rev;
};

vector<vector<edge>> to;
vector<bool> used;
void addE(ll u, ll v, ll w) {
  to[u].push_back({v, w, (ll)to[v].size()});
  to[v].push_back({u, 0, (ll)to[u].size() - 1});
}

ll dfs(ll u, ll t, ll f) {
  assert(f > 0);
  if (u == t) return f;
  used[u] = true;
  for (edge& e : to[u]) {
    if (used[e.to] || e.cap <= 0) continue;
    ll d = dfs(e.to, t, min(f, e.cap));
    if (d == 0) continue;
    e.cap -= d;
    to[e.to][e.rev].cap += d;
    return d;
  }
  return 0;
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, g, e;
  cin >> n >> g >> e;
  to.resize(n + 1);
  rep(i, g) {
    ll p;
    cin >> p;
    addE(p, n, 1);
    addE(n, p, 1);
  }
  rep(i, e) {
    ll a, b;
    cin >> a >> b;
    addE(a, b, 1);
    addE(b, a, 1);
  }

  ll ans = 0;
  while (true) {
    used.assign(n + 1, false);
    ll add = dfs(0, n, INF);
    if (add == 0) {
      cout << ans << endl;
      return 0;
    } else
      ans += add;
  }

  return 0;
}
