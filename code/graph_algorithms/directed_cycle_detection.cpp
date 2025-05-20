vector<int> edges[N];
int seen[N];
int active[N];

bool has_cycle(int u) {
    if (seen[u]) return false;
    seen[u] = true;
    active[u] = true;
    for (int v : edges[u]) {
        if (active[v] || has_cycle(v)) return true;
    }
    active[u] = false;
    return false;
}