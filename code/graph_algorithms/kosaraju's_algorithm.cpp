int scc[N];
vector<int> edges[N], edges_r[N];
int n, m;

bool seen[N], seen_r[N];
int postorder[N];
int p = 0;

void dfs(int u) {
    if (seen[u]) return;
    seen[u] = true;
    for (int v : edges[u]) dfs(v);
    postorder[p++] = u;
}

void dfs_r(int u, int mark) {
    if (seen_r[u]) return;
    seen_r[u] = true;
    scc[u] = mark;
    for (int v : edges_r[u]) dfs_r(v, mark);
}

int compute_sccs() {
    int sccs = 0;
    for (int i = 1; i <= n; i++)
        if (!seen[i]) dfs(i);

    for (int i = p - 1; i >= 0; i--) {
        int u = postorder[i];
        if (!seen_r[u]) dfs_r(u, sccs++);
    }
    return sccs;
}