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
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vvP = vector<vector<P>>;
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

using mint = modint998244353;

/* Macros reg. ends here */

const ll INF = 1LL << 50;

using S = pair<int, int>;
using F = ll;

struct LzyST {
  int n, d, ofst;
  vector<S> as;
  vector<F> lzy;

  const S E = {0, 0};
  const F id = 0;

  S op(S x, S y){
    auto [a, b] = x;
    auto [p, q] = y;
    return {a + p, b + q};
  }

  S mpg(F f, S x){
    S ret;
    if (f == id) {
      ret = x;
    } else {
      auto [a, b] = x;
      ret = {b - a, b};
    }
    return ret;
  }

  F cmp(F f2, F f1){
    return (f2 + f1)%2;
  }

  LzyST(int _n){
    n = 2, d = 0;
    while(n < 2*_n){
      n <<= 1;
      d++;
    }
    ofst = n >> 1;
    as.assign(n, E);
    lzy.assign(n, id);
  }

  void set(int p, S x){
    int k = p + ofst;
    rrepLRE(i, d, 0) apply_at(k >> i);
    as[k] = x;
    repLRE(i, 0, d) update(k >> i);
  }

  void apply(int l, int r, F f){
    l += ofst, r += ofst;
    rrepLRE(i, d, 0) if(l != ((l >> i) << i)) apply_at(l >> i);
    rrepLRE(i, d, 0) if(r != ((r >> i) << i)) apply_at((r - 1) >> i);

    int l2 = l, r2 = r;
    while(l < r){
      if(l & 1){
        lzy[l] = cmp(f, lzy[l]);
        l++;
      }
      l >>= 1;
      if(r & 1){
        lzy[r-1] = cmp(f, lzy[r-1]);
        r--;
      }
      r >>= 1;
    }

    l = l2, r = r2;
    repLRE(i, 0, d) if(l != ((l >> i) << i)) update(l >> i);
    repLRE(i, 0, d) if(r != ((r >> i) << i)) update((r - 1) >> i);
  }

  S prod(int l, int r){
    l += ofst, r += ofst;
    rrepLRE(i, d, 0) if(l != ((l >> i) << i)) apply_at(l >> i);
    rrepLRE(i, d, 0) if(r != ((r >> i) << i)) apply_at((r - 1) >> i);

    S sml = E, smr = E;
    while(l < r){
      if(l & 1){
        apply_at(l);
        sml = op(sml, as[l]);
        l++;
      }
      l >>= 1;
      if(r & 1){
        apply_at(r-1);
        smr = op(as[r-1], smr);
        r--;
      }
      r >>= 1;
    }

    return op(sml, smr);
  }

private:
  void apply_at(int k){
    as[k] = mpg(lzy[k], as[k]);
    if(k < ofst){
      lzy[2*k] = cmp(lzy[k], lzy[2*k]);
      lzy[2*k + 1] = cmp(lzy[k], lzy[2*k + 1]);
    }
    lzy[k] = id;
  }

  void update(int k){
    apply_at(k);
    if(k < ofst){
      apply_at(2*k);
      apply_at(2*k + 1);
      as[k] = op(as[2*k], as[2*k + 1]);
    }
  }
  
};

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, q;
  cin >> n >> q;

  LzyST lseg(n);

  rep(i, n) lseg.set(i, {0, 1});

  rep(_, q){
    ll t, l, r;
    cin >> t >> l >> r;
    if(t == 1){
      lseg.apply(l, r, 1);
    } else {
      assert(t == 2);
      auto [a, b] = lseg.prod(l, r);
      cout << a << endl;
    }
  }

  return 0;
}
