int dp[N + 2][S + 1];

for (int i = N; i >= 1; --i) {
    for (int r = 0; r <= S; ++r) {
        int m = dp[i + 1][r];
        if (r - s[i] >= 0) m = max(m, dp[i + 1][r - s[i]] + v[i]);
        dp[i][r] = m;
    }
}