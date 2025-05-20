typedef long long ll;

const int N = 1001001;
const int MOD = 1e9 + 7;
ll f[N + 1];
ll inv[N + 1];
ll modpow(ll a, ll b, int c);  // as earlier

ll choose(ll n, ll r) { return ((f[n] * inv[r]) % MOD * inv[n - r]) % MOD; }

int main() {
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = (i * f[i - 1]) % MOD;

    inv[N] = modpow(f[N], MOD - 2, MOD);
    for (int i = N; i >= 1; --i) inv[i - 1] = (inv[i] * i) % MOD;
}