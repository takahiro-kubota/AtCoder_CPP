template <typename T>
struct SegTree {
  ll n, ofst;
  vector<T> arr;

  SegTree(const ll _n) {
    n = 1;
    while (n < 2 * _n) n <<= 1;
    arr.assign(n, INF);
    ofst = n >> 1;
  }

  void update(ll i, T x) {
    i += ofst;
    arr[i] = x;
    while (true) {
      i /= 2;
      if (i == 0) break;
      arr[i] = min(arr[2 * i], arr[2 * i + 1]);
    }
  }

  T get(ll l, ll r) { // [l, r)
    T ret = INF;
    l += ofst, r += ofst;
    while (l < r) {
      if (l % 2 == 1) {
        chmin(ret, arr[l]);
        l++;
      }
      l /= 2;
      if (r % 2 == 1) {
        chmin(ret, arr[r - 1]);
        r--;
      }
      r /= 2;
    }
    return ret;
  }
};

// range update, one-point minimum
// template <typename T>
// struct SegTree {
//   ll n, ofst;
//   vector<T> arr;

//   SegTree(const ll _n) {
//     n = 1;
//     while (n < 2 * _n) n <<= 1;
//     arr.assign(n, INF);
//     ofst = n >> 1;
//   }

//   ll get(ll i) {
//     i += ofst;
//     ll ret = arr[i];    
//     while (true) {
//       i /= 2;
//       if (i == 0) break;
//       chmin(ret, arr[i]);
//     }
//     return ret;
//   }

//   void update(ll l, ll r, ll x) { // [l, r)
//     l += ofst, r += ofst;
//     while (l < r) {
//       if (l % 2 == 1) {
//         arr[l] = x;
//         l++;
//       }
//       l /= 2;
//       if (r % 2 == 1) {
//         arr[r-1] = x;
//         r--;
//       }
//       r /= 2;
//     }
//   }
// };