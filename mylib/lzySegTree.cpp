struct LzyST {
  int n, d, ofst;
  vector<S> as;
  vector<F> lzy;

  const S E = {0, 0, 0, 0};
  const F id = 0;

  S op(S x, S y){
    auto [a, b, c, d] = x;
    auto [p, q, r, s] = y;
    return {a + p, b + q, c + r + b*p, d + s + a*q};
  }

  S mpg(F f, S x){
    S ret;
    if (f == id) {
      ret = x;
    } else {
      auto [a, b, c, d] = x;
      ret = {b, a, d, c};
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