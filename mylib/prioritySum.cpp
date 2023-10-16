// PrioritySumStructure(昇(降)順k個の和) ------------------------------
template< typename T, typename Compare, typename RCompare >
struct PrioritySumStructure {
 
  size_t k;
  T sum;
 
  priority_queue< T, vector< T >, Compare > in, d_in;
  priority_queue< T, vector< T >, RCompare > out, d_out;
 
  PrioritySumStructure(int k) : k(k), sum(0) {}
 
  void modify() {
    while(in.size() - d_in.size() < k && !out.empty()) {
      auto p = out.top();
      out.pop();
      if(!d_out.empty() && p == d_out.top()) {
        d_out.pop();
      } else {
        sum += p;
        in.emplace(p);
      }
    }
    while(in.size() - d_in.size() > k) {
      auto p = in.top();
      in.pop();
      if(!d_in.empty() && p == d_in.top()) {
        d_in.pop();
      } else {
        sum -= p;
        out.emplace(p);
      }
    }
    while(!d_in.empty() && in.top() == d_in.top()) {
      in.pop();
      d_in.pop();
    }
  }

  void insert(T x) {
    in.emplace(x);
    sum += x;
    modify();
  }
 
  void erase(T x) {
    assert(size());
    if(!in.empty() && in.top() == x) {
      sum -= x;
      in.pop();
    } else if(!in.empty() && RCompare()(in.top(), x)) {
      sum -= x;
      d_in.emplace(x);
    } else {
      d_out.emplace(x);
    }
    modify();
  }
 
  void set_k(size_t kk) {
    k = kk;
    modify();
  }
 
  T query() const { return sum; }
  size_t get_k() const { return k; }
  size_t size() const { return in.size() + out.size() - d_in.size() - d_out.size(); }
};
 
template< typename T >
using BigSum = PrioritySumStructure< T, greater< T >, less< T > >;
template< typename T >
using SmallSum = PrioritySumStructure< T, less< T >, greater< T > >;
/*
大きい方からK個
BigSum<T> B(k);
小さい方からK個
SmallSum<T> S(k);
insert(x) : 追加
erase(x) : 削除
query() : k個の和を取得(要素数がkに満たない時はすべての和を返す)
set_k() : kを変更
get_k() : kを取得
size() : 要素数を取得
*/
// PrioritySumStructure(昇(降)順k個の和) ------------------------------

struct S {
  ll h;
  multiset<ll> s, t;
  S(ll h): h(h) {}
  void fix() {
    while (h <= 0) {
      h += *s.rbegin();
      t.insert(*s.rbegin());
      s.erase(prev(s.end()));
    }
    while (t.size() && h > *t.begin()) {
      h -= *t.begin();
      s.insert(*t.begin());
      t.erase(t.begin());
    }
  }
  void add(ll x) {
    if (t.size() && *t.begin() < x) t.insert(x);
    else h -= x, s.insert(x);
    fix();
  }
  void del(ll x) {
    if (t.find(x) != t.end()) {
      t.erase(t.find(x));
    } else {
      h += x;
      s.erase(s.find(x));
      fix();
    }
  }
  int get() { return t.size();}
};
