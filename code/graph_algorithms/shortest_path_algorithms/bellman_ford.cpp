const long long INF = 1e9 + 7;

struct edge {
    int u, v, w;  // u -> v of weight w
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int n, m, cycleStart;
vector<long long> dist;
vector<int> parent;
vector<edge> edges;
set<int> visited;

bool relax() {
    bool relaxed = false;
    for (edge e : edges) {
        if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
            relaxed = true;
            dist[e.v] = dist[e.u] + e.w;
            parent[e.v] = e.u;
            cycleStart = e.v;
            visited.insert(e.u);
        }
    }
    return relaxed;
}

bool bellman_ford(int start) {
    fill(dist.begin(), dist.end(), INF);
    fill(parent.begin(), parent.end(), -1);
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++)
        if (!relax()) break;

    return relax();
}