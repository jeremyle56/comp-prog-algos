vector<int> edges[N];
int preorder[N];
int T = 0;
int reach[N];
vector<pair<int, int>> bridges;

void dfs(int u, int from = -1) {
    preorder[u] = T++;
    reach[u] = preorder[u];

    for (int v : edges[u])
        if (v != from) {
            if (preorder[v] == -1) {
                dfs(v, u);
                if (reach[v] == preorder[v]) bridges.emplace_back(u, v);
            }
            reach[u] = min(reach[u], reach[v]);
        }
}