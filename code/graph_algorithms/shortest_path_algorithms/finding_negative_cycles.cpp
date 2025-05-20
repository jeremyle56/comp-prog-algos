int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    dist.resize(n);
    parent.resize(n);

    bool res = false;
    for (int i = 0; i < n; ++i) {
        if (visited.find(i) == visited.end() && bellman_ford((i))) {
            res = true;
            break;
        }
    }

    if (!res) cout << "NO\n";
    else {
        cout << "YES\n";

        for (int i = 0; i < n; ++i) cycleStart = parent[cycleStart];

        vector<int> cycle;
        for (int v = cycleStart;; v = parent[v]) {
            cycle.push_back(v);
            if (v == cycleStart && cycle.size() > 1) break;
        }

        reverse(cycle.begin(), cycle.end());
        for (int v : cycle) cout << v << ' ';
    }
}