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

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, k;
  cin >> n >> k;

  vll BIT(n + 2, 0);  // 1-indexed

  auto badd = [&](ll i, ll x) {
    while (i <= n + 1) {
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

  vll csum(n + 1, 0), bs(n + 1);
  bs[0] = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    csum[i + 1] = csum[i] + a;
    bs[i+1] = csum[i+1] - k*(i+1);
  }

  {  // compress x
    map<ll, ll> mp;
    rep(i, n+1) mp[bs[i]] = 0;
    ll j = 1;
    for (auto& x : mp) x.second = j++;
    rep(i, n+1) bs[i] = mp[bs[i]];
  }

  ll ans = 0;
  rep(i, n+1){
    ans += bget(bs[i]);
    badd(bs[i], 1);
  }

  cout << ans << endl;

  return 0;
}
