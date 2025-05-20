int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges_r[b].push_back(a);
    }

    int nsccs = compute_sccs();
    for (int i = 1; i <= n; ++i) {
        for (int j : edges[i]) {
            if (scc[i] != scc[j]) dag[scc[i]].insert(scc[j]);
        }
    }

    vector<int> topo = topsort();
}