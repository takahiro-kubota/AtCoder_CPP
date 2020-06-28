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

vvll to, ot;
vll ord;
vector<bool> seen;
void dfs(ll u) {
  seen[u] = true;
  for (ll v : to[u]) {
    if (seen[v]) continue;
    dfs(v);
  }
  ord.push_back(u);
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, m;
  cin >> n >> m;
  to.resize(n), ot.resize(n);
  seen.resize(n);
  rep(i, n + m - 1) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    to[a].push_back(b);
    ot[b].push_back(a);
  }

  rep(i, n) {
    if (seen[i]) continue;
    dfs(i);
  }
  Reverse(ord);

  vll myord(n);
  rep(i, n) myord[ord[i]] = i;

  rep(i, n) {
    ll ans = 0;
    ll pos = -1;
    if (ot[i].size() == 0) {
      ans = -1;
      goto PUT;
    }
    for (ll u : ot[i]) {
      if (myord[u] > pos) {
        ans = u;
        pos = myord[u];
      }
    }
  PUT:
    cout << ans + 1 << endl;
  }

  return 0;
}
