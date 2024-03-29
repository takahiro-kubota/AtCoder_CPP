struct V {
  ll x, y;
  V(ll x = 0, ll y = 0) : x(x), y(y) {}
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
  V& operator*=(ll s) {
    x *= s;
    y *= s;
    return *this;
  }
  V operator*(ll s) const { return V(*this) *= s; }
  V& operator/=(ll s) {
    x /= s;
    y /= s;
    return *this;
  }
  V operator/(ll s) const { return V(*this) /= s; }
  ll dot(const V& v) const { return x * v.x + y * v.y; }
  ll cross(const V& v) const { return x * v.y - v.x * y; }

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

