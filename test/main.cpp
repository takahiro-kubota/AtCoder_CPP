#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
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
#include <unordered_set>
#include <vector>
#include <random>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

/* types */
using ll = long long;
using l3 = __int128_t;
using ull = unsigned long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vvvvll = vector<vvvll>;
using vP = vector<P>;
using vvP = vector<vector<P>>;
using vT = vector<T>;
using vvT = vector<vT>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;

/* macro */
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Uniq(v) Sort(v), v.erase(unique(v.begin(), v.end()), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define All(a) (a).begin(),(a).end()
#define Lower_bound(v, y) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), y))
#define Upper_bound(v, y) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), y))
#define popcnt(x) (ll(__builtin_popcountll(x)))
#define sz(x) (ll)x.size()
#define drop(s) {cout << s << endl, exit(0);}

/* input */
template <class T> void scan(T& a) { cin >> a; }
template <class T> void scan(vector<T>& a) {
    for(auto& i : a) scan(i);
}
void IN() {}
template <class T, class... S> void IN(T &hd, S &...tl) {
    scan(hd);
    IN(tl...);
}
void INd() {}
template <class T, class... S> void INd(T &hd, S &...tl) {
    scan(hd);
    --hd;
    INd(tl...);
}
#define LL(...) \
    ll __VA_ARGS__; \
    IN(__VA_ARGS__)
#define LLd(...) \
    ll __VA_ARGS__; \
    INd(__VA_ARGS__)
#define STR(...) \
    string __VA_ARGS__; \
    IN(__VA_ARGS__)
#define CHR(...) \
    char __VA_ARGS__; \
    IN(__VA_ARGS__)
#define LD(...) \
    ld __VA_ARGS__; \
    IN(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size); \
    for(int i = 0; i < size; i++) IN(name[i])
#define VECd(type, name, size) \
    vector<type> name(size); \
    for(int i = 0; i < size; i++) INd(name[i])
#define VEC2(type, name1, name2, size) \
    vector<type> name1(size), name2(size); \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i])
#define VEC2d(type, name1, name2, size) \
    vector<type> name1(size), name2(size); \
    for(int i = 0; i < size; i++) INd(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size) \
    vector<type> name1(size), name2(size), name3(size); \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])
#define VEC3d(type, name1, name2, name3, size) \
    vector<type> name1(size), name2(size), name3(size); \
    for(int i = 0; i < size; i++) INd(name1[i], name2[i], name3[i])
#define VEC4(type, name1, name2, name3, name4, size) \
    vector<type> name1(size), name2(size), name3(size), name4(size); \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i], name4[i]);
#define VEC4d(type, name1, name2, name3, name4, size) \
    vector<type> name1(size), name2(size), name3(size), name4(size); \
    for(int i = 0; i < size; i++) INd(name1[i], name2[i], name3[i], name4[i]);
#define VV(type, name, h, w) \
    vector<vector<type>> name(h, vector<type>(w)); \
    IN(name)
#define VVd(type, name, h, w) \
    vector<vector<type>> name(h, vector<type>(w)); \
    INd(name)

vvll graph_read(ll n, ll m, bool directed=false){
  vvll to(n);
  rep(i, m){
    LLd(u, v);
    to[u].emplace_back(v);
    if(!directed) to[v].emplace_back(u);
  }
  return to;
}

vvP graph_read_wt(ll n, ll m, bool directed=false){
  vvP to(n);
  rep(i, m){
    LLd(u, v);
    LL(w);
    to[u].emplace_back(v, w);
    if(!directed) to[v].emplace_back(u, w);
  }
  return to;
}

/* output */
template <class Ch, class Tr, class Container> std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr>& os, const Container& x) {
  bool f = true;
  for(auto &y : x) {
    os << (f ? "" : " ") << y;
    f = false;
  }
  return os;
}

void OUT() { cout << endl; }
template <class Hd, class... Tl> void OUT(const Hd& hd, const Tl& ...tl) {
  cout << hd;
  if(sizeof...(tl)) cout << ' ';
  OUT(tl...);
}

template <class Container> void ONL(const Container& x) {
  bool f = true;
  for(auto &y : x) {
    cout << (f ? "" : "\n") << y;
    f = false;
  }
  cout << endl;
  return;
}

// yes/no etc...
void first(bool i = true){ OUT(i?"first":"second"); }
void First(bool i = true){ OUT(i?"First":"Second"); }
void yes(bool i = true){ OUT(i?"yes":"no"); }
void Yes(bool i = true){ OUT(i?"Yes":"No"); }
void No(){ OUT("No"); }
void YES(bool i = true){ OUT(i?"YES":"NO"); }
void NO(){ OUT("NO"); }
void possible(bool i = true){ OUT(i?"possible":"impossible"); }
void Possible(bool i = true){ OUT(i?"Possible":"Impossible"); }
void POSSIBLE(bool i = true){ OUT(i?"POSSIBLE":"IMPOSSIBLE"); }

/* debug */
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

/* constants */
ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr ll INF = (1LL << 60);
//constexpr ld eps = 1E-10;

/* mod related */
//constexpr ll mod = 1000000007;
constexpr ll mod = 998244353;
//ll mod;
struct mint
{
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  bool operator==(mint a){
    return (x==a.x);
  }
  bool operator!=(mint a){
    return (x!=a.x);
  }
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
class modutils
{
  vector<mint> fact, invfact;
public:
  modutils(int n = 200005) : fact(n + 1), invfact(n + 1)
  {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
      fact[i] = fact[i - 1] * i;
    invfact[n] = fact[n].inv();
    for (int i = n; i >= 1; i--)
      invfact[i - 1] = invfact[i] * i;
  }
  mint pow(mint x, ll n) { return x.pow(n); }
  mint comb(ll n, ll k)
  {
    if (n < 0 || k < 0 || n < k)
      return 0;
    return fact[n] * invfact[k] * invfact[n - k];
  }
  mint perm(ll n, ll k)
  {
    if (n < 0 || k < 0 || n < k)
      return 0;
    return fact[n] * invfact[n - k];
  }
  mint hom(ll n, ll k) { return comb(n + k - 1, k); }
  mint fac(ll n) { return fact[n]; }
  mint invfac(ll n) { return invfact[n]; }
};
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

/* segtree functions */
ll xadd(ll a, ll b) { return a+b; }
ll xmax(ll a, ll b) { return max(a, b); }
ll xmin(ll a, ll b) { return min(a, b); }
ll xinf() { return INF; }
ll xminf() { return -INF; }
ll xzero() { return 0LL; }

/* utility */
ll mymod(ll a, ll b) { return (a%b+b)%b; }

template<class T> T cdv(const T &a, const T &b){
    if(a%b==0){return a/b;}
    if(a>=0){return (a/b)+1;}
    else{return -((-a)/b);}
}
template<class T> T fdv(const T &a, const T &b){
    if(a%b==0){return a/b;}
    if(a>=0){return (a/b);}
    else{return -((-a)/b)-1;}
}

template<class T> auto min(const T& a){ return *min_element(All(a)); }
template<class T> auto max(const T& a){ return *max_element(All(a)); }
template<class T> T acc(const vector<T>& as) { return accumulate(All(as), T(0)); }

template<class T> T dist2(T x, T y, T a, T b){
  return (x-a)*(x-a)+(y-b)*(y-b);
}

ld ld_dist(ld x, ld y, ld a, ld b){
  return sqrtl(dist2(x, y, a, b));
}

vll iota(int n, int st=0) {
    vll as(n);
    iota(as.begin(), as.end(), st);
    return as;
}

template <class T> inline bool chmax(T &a, T b){
  if (a < b){
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b){
  if (a > b){
    a = b;
    return 1;
  }
  return 0;
}

template <class S> vector<pair<S, ll>> runLength(const vector<S> &v) {
  vector<pair<S, ll>> res;
  for(const S& e : v) {
    if(res.empty() || res.back().first != e)
      res.emplace_back(e, 1);
    else
      res.back().second++;
  }
  return res;
}
vector<pair<char, ll>> runLength(const string &v) {
    vector<pair<char, ll>> res;
    for(const char& e : v) {
        if(res.empty() || res.back().first != e)
            res.emplace_back(e, 1);
        else
            res.back().second++;
    }
    return res;
}

// 非負整数値 x の大きさが ll に収まっている必要がある
string radix_conversion(const string& x, ll from, ll to){
  const std::string table = "0123456789ABCDEF";
  assert((2 <= from && from <= 16) && (2 <= to && to <= 16));

  ll sum = 0;
  for(char c : x){
    sum = sum * from + table.find(c);
  }

  std::string res = "";
  do {
      ll mod = sum % to;
      res = table[mod] + res;
      sum /= to;
  } while (sum);

  return res;
}

// 座標圧縮
// 三つ組 (asの座標圧縮の結果, 逆変換, 順変換テーブル) を返す
tuple<vll, vll, map<ll, ll>> compress(const vll& as){
  ll n = as.size();
  map<ll, ll> mp;
  ll j = 0;
  for(auto  a : as) mp[a] = 0;
  vll rv(n);
  for(auto& [k, v] : mp) {
    v = j;
    rv[j] = k;
    j++;
  }
  vll cs(n);
  rep(i, n) {
    cs[i] = mp[as[i]];
  }
  return make_tuple(cs, rv, mp);
}

/* number theory */
ll isqrt_floor(ll n){
  assert(n>=0);
  __uint128_t nn = n;
  __uint128_t l = 0, r = 1E19;
  while(l + 1 < r){
    __uint128_t mid = (l + r)/2;
    if(mid*mid <= nn){
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

l3 ipow(l3 x, l3 t) {
  if (t == 0) return 1;
  l3 a = ipow(x, t >> 1);
  a *= a;
  if (t & 1) a *= x;
  return a;
}

l3 ipow(l3 x, l3 t, l3 q) {
  if (t == 0) return 1;
  l3 a = ipow(x, t >> 1, q);
  a = (a*a)%q;
  if (t & 1) a = (x*a)%q;
  return a;
}

// nの約数を小さい順に得る
vll divisors(ll n){
  vll ret;
  for (ll i = 1; i*i <= n; i++){
    if(n % i == 0){
      ret.push_back(i);
      if(n/i != i) ret.push_back(n/i);
    }
  }
  Sort(ret);
  return ret;
}

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> ret;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1) ret[n] = 1;
  return ret;
}

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
ll extgcd(ll a, ll b, ll& x, ll& y){
  if(b == 0){
    x = 1, y = 0;
    return a;
  } else {
    ll g = extgcd(b, a%b, y, x);
    y -= (a/b)*x;
    return g;
  }
}

/* binary/ternary search */
template <class T, class F> T bin_search(T ok, T ng, const F& f) {
  while(abs(ok-ng) > 1) {
    T mi = (ok+ng)/2;
    if(f(mi)) ok = mi;
    else ng = mi;
  }
  return ok;
}

template <class F> ld bin_search_real(ld ok, ld ng, const F& f, int iter = 80) {
  while(iter--) {
    ld mi = (ok+ng)/2;
    if(f(mi)) ok = mi;
    else ng = mi;
  }
  return ok;
}
template <class T, class F> T ter_search_real_bot(T l, T r, const F& f, int iter = 100) {
  // itrの値の大きすぎ/小さすぎに注意
  while(iter--) {
    T nl = (l*2+r)/3;
    T nr = (l+r*2)/3;
    if(f(nl)<f(nr)) r = nr;
    else l = nl;
  }
  return l;
}

template <class T, class F> T ter_search_real_top(T l, T r, const F& f, int iter = 100) {
  // 動作未検証
  while(iter--) {
    T nl = (l*2+r)/3;
    T nr = (l+r*2)/3;
    if(f(nl)>f(nr)) r = nr;
    else l = nl;
  }
  return l;
}

/* cumlative sum */
template<class T> struct cumSum {
  vector<T> cs;
  cumSum(vector<T> as){
    ll n = as.size();
    cs.assign(n+1, 0);
    rep(i, n) cs[i+1] = cs[i] + as[i];
  }
  T get(ll l, ll r) { return cs[r]-cs[l]; };
};

template<class T> struct cumSum2D {
  vector<vector<T>> cs;
  cumSum2D(vector<vector<T>> as){
    ll n = as.size();
    ll m = as[0].size();
    cs.assign(n+1, vector<T>(m+1, 0));
    rep(i, n) rep(j, m) cs[i+1][j+1] = as[i][j] + cs[i+1][j] + cs[i][j+1] - cs[i][j];
  }
  T get(ll a, ll b, ll x, ll y) { return cs[x][y]-cs[a][y]-cs[x][b]+cs[a][b]; };
};

/* enumeration */
// isからm要素を組み合わせて得られる配列達を返す
vvll combinations(vll is, ll m){
  ll n = is.size();
  vvll ans;
  auto f = [&](auto f, ll x, vll& now) -> void {
    if(sz(now)==m){
      ans.push_back(now);
      return;
    }
    repE(i, x, n-(m-sz(now))){
      now.push_back(is[i]);
      f(f, i+1, now);
      now.pop_back();
    }
  };
  vll now;
  f(f, 0, now);
  return ans;
}
//-- ends here --

int main(){
  cout << fixed << setprecision(15);

  
  
  return 0;
}
