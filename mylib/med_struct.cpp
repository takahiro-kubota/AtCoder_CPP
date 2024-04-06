struct Med {
  multiset<ll> lst;
  multiset<ll, greater<ll>> sst;

  void balance(){
    if(lst.size() > sst.size()) {
      auto itr = lst.begin();
      sst.insert(*itr);
      lst.erase(itr);
    } else if((ll)lst.size() < (ll)sst.size()-1){
      auto itr = sst.begin();
      lst.insert(*itr);
      sst.erase(itr);
    }
    if(!lst.empty() && !sst.empty() && *lst.begin() < *sst.begin()){
      auto itr = lst.begin(); 
      auto jtr = sst.begin();
      ll x = *itr, y = *jtr;
      lst.erase(itr);
      lst.insert(y);
      sst.erase(jtr);
      sst.insert(x);
    }
  }

  void add(ll x){
    lst.insert(x);
    balance();
  }

  void del(ll x){
    auto itr = sst.find(x);
    if(itr != sst.end()){
      sst.erase(itr);
      balance();
      return;
    } 
    auto jtr = lst.find(x);
    if(jtr != lst.end()){
      lst.erase(jtr);
      balance();
      return;
    } 
  }

  ll get(){
    ll ret = -1;
    if(sst.size()==lst.size()){
      ret = (*sst.begin()+*lst.begin())/2;
    } else {
      ret = *sst.begin();
    }
    return ret;
  }

  void show(){
    debug(lst);
    debug(sst);
  }
};