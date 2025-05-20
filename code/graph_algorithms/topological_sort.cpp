set<int> dag[N];  // edges
bool seen_dag[N];

void compute_topsort(int u, vector<int>& postorder) {
    if (seen_dag[u]) return;
    seen_dag[u] = true;
    for (int v : dag[u]) compute_topsort(v, postorder);
    postorder.push_back(u);
}

vector<int> topsort() {
    vector<int> res;
    for (int i = 0; i < nsccs; i++) compute_topsort(i, res);
    reverse(res.begin(), res.end());
    return res;
}