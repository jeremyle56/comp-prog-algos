struct edge {
    int u, v, w;
};
bool operator<(const edge& a, const edge& b) { return a.w < b.w; }

edge edges[N];
int root(int u);          // union-find root with path compression
void join(int u, int v);  // union-find join with size heuristic

int mst() {
    sort(edges, edges + m);  // sort by increasing weight
    int total_weight = 0;
    for (int i = 0; i < m; i++) {
        edge& e = edges[i];
        if (root(e.u) != root(e.v)) {
            total_weight += e.w;
            join(e.u, e.v);
        }
    }
    return total_weight;
}