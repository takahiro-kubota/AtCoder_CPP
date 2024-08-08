// sample ABC137

void polyadd(const vm& as, const vm& bs, vm& cs){
  ll na = as.size(), nb = bs.size(); // nx = deg(x)+1
  ll nc = max(na, nb);
  cs.assign(nc, 0);
  rep(i, nc) {
    mint a = i<na ? as[i] : 0;
    mint b = i<nb ? bs[i] : 0;
    cs[i] = a + b;
  }
}

void polymul(const vm& as, const vm& bs, vm& cs){
  ll na = as.size(), nb = bs.size(); // nx = deg(x)+1
  ll nc = na+nb-1;
  cs.assign(nc, 0);
  rep(i, na) rep(j, nb){
    cs[i+j] += as[i]*bs[j];
  }
}

void polydiv(const vm& as, const vm& bs, vm& qs, vm& rs){
  ll na = as.size(), nb = bs.size(); // nx = deg(x)+1
  if(na < nb) {
    qs = vm(1, 0);
    rs = as;
    return;
  }
  qs.assign(na-nb+1, 0);
  vm cs = as;
  mint binv = mint(1)/bs[nb-1];
  rrepE(i, na-nb, 0){
    qs[i] = cs[nb-1+i]*binv;
    repE(j, 1, nb-1){
      cs[nb-1+i-j] -= qs[i]*bs[nb-1-j];
    }
  }
  rs.assign(nb-1, 0);
  rrepE(i, nb-2, 0) rs[i] = cs[i];
}

void lcomp(vm& xs, vm& ys, vm& ans){
  assert(xs.size()==ys.size());
  ll p = xs.size();
  // ptot
  vm ptot = {1};
  rep(i, p){
    vm exi = {p-i, 1};
    vm nptot;
    polymul(ptot, exi, nptot);
    swap(ptot, nptot);
  }

  // ans
  ans.assign(p, 0); // b0, b1, ..., b_{p-1}
  rep(i, p){
    // coe
    mint coe = 1;
    rep(j, p) if(i!=j) coe *= (i-j);
    coe = coe.inv()*ys[i];

    // poly
    vm exi = {p-i, 1};
    vm qs, rs;
    polydiv(ptot, exi, qs, rs);
    rep(j, p) ans[j] += qs[j]*coe;
  }
}