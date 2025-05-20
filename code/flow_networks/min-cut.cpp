void check_reach(int u, vector<bool>& seen) {
    if (seen[u]) return;
    seen[u] = true;
    for (int v : adjList[u])
        if (adjMat[u][v] > 0) check_reach(v, seen);
}

vector<pair<int, int>> min_cut(int s, int t) {
    ll value = dinic(s, t);

    vector<bool> seen(n, false);
    check_reach(s, seen);

    vector<pair<int, int>> ans;
    for (int u = 0; u < n; u++) {
        if (!seen[u]) continue;
        for (int v : adjList[u])
            if (!seen[v] && !is_virtual[u][v])  // need to record this in add_edge()
                ans.emplace_back(u, v);
    }
    return ans;
}