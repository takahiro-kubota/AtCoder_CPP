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

//#include <atcoder/all>
//using namespace atcoder;

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

  ll n, m;
  cin >> n >> m;

  vll ls(m), rs(m), as(m), bs(m);

  vll ans(n, 0);
  rep(i, m){
    cin >> ls[i] >> rs[i] >> as[i] >> bs[i];
    ll l = ls[i]-1, r = rs[i]-1;
    assert(r >= l);
    repLRE(j, l, r) ans[j] += as[i] + (j - l)*bs[i]; // O(nm)
    //rep(j, n) cout << ans[j] << (j == n - 1 ? '\n' : ' ');
  }
  rep(i, n) cout << ans[i] << (i == n - 1 ? '\n' : ' ');

  vll ans2(n+1, 0);
  vll ofst(n+1, 0);
  rep(i, m){
    ll l = ls[i]-1, r = rs[i]-1;
    ans2[l+1] += bs[i];
    ans2[r+1] -= bs[i];
    ofst[l]   += as[i];
    ofst[r+1] -= as[i] + (r - l)*bs[i];
  } // O(m)
  rep(i, n) ans2[i+1] += ans2[i];
  rep(i, n) ans2[i]   += ofst[i];
  rep(i, n) ans2[i+1] += ans2[i];
  rep(i, n) {
    assert(ans[i] == ans2[i]);
    cout << ans2[i] << (i == n - 1 ? '\n' : ' ');
  } // O(n)


  return 0;
}
