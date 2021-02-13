using S = long long;

struct SegTree {
  int n, ofst;
  vector<S> as;

  const S E = 0;
  S op(S x, S y){
    return x ^ y;
  }

  SegTree(const int _n) {
    n = 1;
    while (n < 2 * _n) n <<= 1;
    as.assign(n, E);
    ofst = n >> 1;
  }

  void set(int p, S x) {
    int k = p + ofst;
    as[k] = x;
    while (true) {
      k /= 2;
      if (k == 0) break;
      as[k] = op(as[2 * k], as[2 * k + 1]);
    }
  }

  S prod(int l, int r) { // [l, r)
    l += ofst, r += ofst;
    S sml = E, smr = E;
    while (l < r) {
      if (l % 2 == 1) {
        sml = op(sml, as[l]);
        l++;
      }
      if (r % 2 == 1) {
        smr = op(as[r - 1], smr);
        r--;
      }
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }
};

// range update, one-point minimum
// template <typename T>
// struct SegTree {
//   int n, ofst;
//   vector<T> arr;

//   SegTree(const int _n) {
//     n = 1;
//     while (n < 2 * _n) n <<= 1;
//     arr.assign(n, INF);
//     ofst = n >> 1;
//   }

//   int get(int i) {
//     i += ofst;
//     int ret = arr[i];    
//     while (true) {
//       i /= 2;
//       if (i == 0) break;
//       chmin(ret, arr[i]);
//     }
//     return ret;
//   }

//   void update(int l, int r, int x) { // [l, r)
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