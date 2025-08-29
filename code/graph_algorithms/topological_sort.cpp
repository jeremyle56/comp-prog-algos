vector<int> topSort(const vector<vector<int>>& g) {
    vector<int> indeg(g.size()), q;

    for (auto& li : g) {
        for (int x : li) ++indeg[x];
    }

    for (int i = 0; i < g.size(); ++i) {
        if (indeg[i] == 0) q.push_back(i);
    }

    for (int j = 0; j < q.size(); ++j) {
        for (int x : g[q[j]]) {
            if (--indeg[x] == 0) q.push_back(x);
        }
    }

    return q;
}