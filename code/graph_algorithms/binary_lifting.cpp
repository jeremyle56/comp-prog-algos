const int N = 200010;
const int D = 30;  // ceil(log2(10^9))
int parent[N][D];

void precomp() {
    for (int i = 1; i <= n; ++i) cin >> parent[i][0];

    for (int j = 1; j < D; ++j) {
        for (int i = 1; i <= n; ++i) parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
}

int kth_parent(int x, int k) {
    for (int j = 0; j < D; ++j) {
        if (k & (1 << j)) x = parent[x][j];
    }
}