ll n, s, k;
cin >> n >> s >> k;

ll mu = ceil(sqrt(n));

map<ll, ll> mp;
repE(j, 0, mu-1){
  ll ky = ((-j*k)%n+n)%n;
  if(!mp.count(ky)) mp[ky] = j;
}

bool found = false;
repE(i, 0, mu-1){
  ll ky = (s+i*mu*k)%n;
  if(mp.count(ky)) {
    cout << i*mu + mp[ky] << endl;
    found = true;
    break;
  }
}