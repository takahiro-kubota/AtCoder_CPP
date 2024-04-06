bool equal(ld a, ld b) {return abs(a-b) < eps;};

struct V {
  ld x, y;
  V(ld x = 0, ld y = 0) : x(x), y(y) {}
  V& operator+=(const V& v) {
    x += v.x;
    y += v.y;
    return *this;
  }
  V operator+(const V& v) const { return V(*this) += v; }
  V& operator-=(const V& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }
  V operator-(const V& v) const { return V(*this) -= v; }
  V& operator*=(ld s) {
    x *= s;
    y *= s;
    return *this;
  }
  V operator*(ld s) const { return V(*this) *= s; }
  V& operator/=(ld s) {
    x /= s;
    y /= s;
    return *this;
  }
  V operator/(ld s) const { return V(*this) /= s; }
  ld dot(const V& v) const { return x * v.x + y * v.y; }
  ld cross(const V& v) const { return x * v.y - v.x * y; }
  ld norm2() const { return x * x + y * y; }
  ld norm() const { return sqrt(norm2()); }

  int ort() const {  // orthant
    if (y > 0)
      return x > 0 ? 1 : 2;
    else
      return x > 0 ? 4 : 3;
  }
  bool operator<(const V& v) const {
    int o = ort(), vo = v.ort();
    if (o != vo) return o < vo;
    return cross(v) > 0;
  }
  V rotate90() const {return V(-y, x); }; // counter clockwise
};
istream& operator>>(istream& is, V& v) {
  is >> v.x >> v.y;
  return is;
}
ostream& operator<<(ostream& os, const V& v) {
  os << "(" << v.x << "," << v.y << ")";
  return os;
}

struct Circle {
  V o; ld r;
  Circle(V o = V(), ld r = 0.0) : o(o), r(r) {}
  vector<V> xp(const Circle& c){
    V vo = c.o - o;
    ld l = vo.norm();
    if(equal(l, 0)) return {}; // fix me: case l == 0 and r == c.r
    if(equal(l + r + c.r, 2*max({l, r, c.r}))) {
      return {o + vo*(r/l)};
    }
    if(l + r + c.r < 2*max({l, r, c.r})) return {};
    ld x = (l*l + r*r - c.r*c.r)/(2*l);
    ld y = sqrt(r*r - x*x);
    V mid = o + vo*(x/l);
    V rvo = vo.rotate90();
    return {mid + rvo*(y/l), mid - rvo*(y/l)};
  }

  bool isInside(const V& p){
    return (p-o).norm() < r + eps;
  }
}; 
