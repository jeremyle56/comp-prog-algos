const ll mod = 1000000007;

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % MOD, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}