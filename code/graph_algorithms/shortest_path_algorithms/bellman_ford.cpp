const ll INF = LLONG_MAX;
struct Edge {
    int a, b, w;
    int s() { return a < b ? a : -a; }
};

struct Node {
    ll dist = INF;
    int prev = -1;
};

void bellmanFord(vector<Node>& nodes, vector<Edge>& edges, int s) {
    nodes[s].dist = 0;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.s() < b.s(); });

    int lim = nodes.size() / 2 + 2;
    for (int i = 0; i < lim; ++i) {
        for (Edge e : edges) {
            Node cur = nodes[e.a], &dest = nodes[e.b];
            if (abs(cur.dist) == INF) continue;
            ll d = cur.dist + e.w;
            if (d < dest.dist) {
                dest.prev = e.a;
                dest.dist = (i < lim - 1 ? d : -INF);
            }
        }
    }

    for (int i = 0; i < lim; ++i) {
        for (Edge e : edges) {
            if (nodes[e.a].dist == -INF) nodes[e.b].dist = -INF;
        }
    }
}