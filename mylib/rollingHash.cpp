struct RollingHash {
  static const ll base1 = 1007, base2 = 2009;
  static const ll mod1 = 1000000007, mod2 = 1000000009;
  vector<ll> hash1, hash2, power1, power2;

  // construct
  RollingHash(const string& S) {
    ll n = (ll)S.size();
    hash1.assign(n + 1, 0);
    hash2.assign(n + 1, 0);
    power1.assign(n + 1, 1);
    power2.assign(n + 1, 1);
    for (ll i = 0; i < n; ++i) {
      hash1[i + 1] = (hash1[i] * base1 + S[i]) % mod1;
      hash2[i + 1] = (hash2[i] * base2 + S[i]) % mod2;
      power1[i + 1] = (power1[i] * base1) % mod1;
      power2[i + 1] = (power2[i] * base2) % mod2;
    }
  }

  // get hash of s[l..r-1]
  inline P get(ll l, ll r) const {
    long long res1 = hash1[r] - hash1[l] * power1[r - l] % mod1;
    if (res1 < 0) res1 += mod1;
    long long res2 = hash2[r] - hash2[l] * power2[r - l] % mod2;
    if (res2 < 0) res2 += mod2;
    return {res1, res2};
  }

  // get lcp of s[a..] and s[b..]
  inline ll getLCP(ll a, ll b) const {
    ll len = min((ll)hash1.size() - a, (ll)hash1.size() - b);
    ll low = 0, high = len;
    while (high - low > 1) {
      ll mid = (low + high) >> 1;
      if (get(a, a + mid) != get(b, b + mid))
        high = mid;
      else
        low = mid;
    }
    return low;
  }
};
