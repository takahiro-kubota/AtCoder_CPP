ll readTime(){
  ll h, m, s, ms;
  scanf("%lld:%lld:%lld.%lld", &h, &m, &s, &ms);
  return (h*3600 + m*60 + s)*1000 + ms;
}

struct Event {
  ll time, type, val;
  Event(ll _time, ll _type, ll _val) : time(_time), type(_type), val(_val) {}
  bool operator<(const Event& e) { return time < e.time; }
};