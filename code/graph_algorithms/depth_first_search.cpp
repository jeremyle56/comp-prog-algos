bool seen[N];

void dfs(int u) {
    if (seen[u]) return;
    seen[u] = true;
    for (int v : edges[u]) dfs(v);
}