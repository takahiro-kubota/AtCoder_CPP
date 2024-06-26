struct UnionFind {
	vector<ll> par;
	vector<ll> rank;
	vector<ll> diff_weight;

	UnionFind(ll n = 1, ll SUM_UNITY = 0) {
		init(n, SUM_UNITY);
	}

	void init(ll n = 1, ll SUM_UNITY = 0) {
		par.resize(n); rank.resize(n); diff_weight.resize(n);
		for (ll i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
	}

	ll root(ll x) {
		if (par[x] == x) {
			return x;
		}
		else {
			ll r = root(par[x]);
			diff_weight[x] += diff_weight[par[x]];
			return par[x] = r;
		}
	}

	ll weight(ll x) {
		root(x);
		return diff_weight[x];
	}

	bool issame(ll x, ll y) {
		return root(x) == root(y);
	}

	bool merge(ll x, ll y, ll w) {
		w += weight(x); w -= weight(y);
		x = root(x); y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y), w = -w;
		if (rank[x] == rank[y]) ++rank[x];
		par[y] = x;
		diff_weight[y] = w;
		return true;
	}

	ll diff(ll x, ll y) {
		return weight(y) - weight(x);
	}
};