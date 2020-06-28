template <typename T>
struct SegTree {
  ll n, ofst;
  vector<T> arr;

  SegTree(const ll _n) {
    n = 1;
    while (n < 2 * _n) n <<= 1;
    arr.resize(n, 0);
    ofst = n >> 1;
  }

  void update(ll i, T x) {
    i += ofst;
    arr[i] = x;
    while (true) {
      i /= 2;
      if (i == 0) break;
      arr[i] = max(arr[2 * i], arr[2 * i + 1]);
    }
  }

  T get(ll l, ll r) {
    T ret = 0;
    l += ofst, r += ofst + 1;
    while (l < r) {
      if (l % 2 == 1) {
        chmax(ret, arr[l]);
        l++;
      }
      l /= 2;
      if (r % 2 == 1) {
        chmax(ret, arr[r - 1]);
        r--;
      }
      r /= 2;
    }
    return ret;
  }
};
