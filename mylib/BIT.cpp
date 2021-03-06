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

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, q;
  cin >> n >> q;
  vll BIT(n + 1, 0);  // 1-indexed

  auto badd = [&](ll i, ll x) {
    while (i <= n) {
      BIT[i] += x;
      i += i & -i;
    }
  };
  auto bget = [&](ll i) {
    ll ret = 0;
    while (i > 0) {
      ret += BIT[i];
      i -= i & -i;
    }
    return ret;
  };

  rep(i, q) {
    ll c;
    cin >> c;
    if (c == 0) {
      ll s, t, x;
      cin >> s >> t >> x;
      badd(t, x);
      badd(s - 1, -x);
    } else {
      ll idx;
      cin >> idx;
      ll ans = bget(idx);
      cout << ans << endl;
    }
  }

  return 0;
}

template <typename T>
struct BIT {
  ll n;
  vector<T> arr;

  BIT(const ll _n) {
    arr.assign(_n + 1, 0);
    n = arr.size();
  }

  void add(ll i, T x) {
    while (i <= n) {
      arr[i] += x;
      i += i & (-i);
    }
  }

  T get(ll i) {
    T ret = 0;
    while (i > 0) {
      ret += arr[i];
      i -= i & (-i);
    }
    return ret;
  }
};