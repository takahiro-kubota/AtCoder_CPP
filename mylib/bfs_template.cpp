queue<ll> q;
vll dp(n, INF);
dp[u] = 0;
q.emplace(u);
while(!q.empty()){
    ll u = q.front();
    q.pop();
    for(ll v : to[u]) if(dp[v]==INF) {
    dp[v] = dp[u]+1;
    q.emplace(v);
    }
}