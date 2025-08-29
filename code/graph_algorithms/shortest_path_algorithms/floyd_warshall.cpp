const ll INF = 1LL << 62;

void floydWarshall(vector<vector<ll>>& m) {
    int n = m.size();
    for (int i = 0; i < n; ++i) m[i][i] = min(m[i][i], 0LL);
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (m[i][k] != INF && m[k][j] != INF) {
                    auto newDist = max(m[i][k] + m[k][j], -INF);
                    m[i][j] = min(m[i][j], newDist);
                }
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        if (m[k][k] < 0) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (m[i][k] != INF && m[k][j] != INF) m[i][j] = -INF;
                }
            }
        }
    }
}