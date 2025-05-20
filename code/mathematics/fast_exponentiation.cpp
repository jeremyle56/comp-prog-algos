typedef long long ll;

ll modpow(ll x, ll n, int m) {
    if (n == 0) return 1;

    ll a = modpow(x, n / 2, m);
    a = a * a % m;
    if (n % 2 == 1) a = a * x % m;
    return a;
}