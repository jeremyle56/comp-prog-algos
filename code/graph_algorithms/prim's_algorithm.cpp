typedef pair<int, int> ii;

vector<ii> edges[N];  // pairs of (weight, v)
bool in_tree[N];
priority_queue<ii, vector<ii>, greater<ii>> pq;

int mst() {
    int total_weight = 0;
    in_tree[0] = true;
    for (auto edge : edges[0]) pq.emplace(edge.first, edge.second);
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();
        if (in_tree[edge.second]) continue;
        in_tree[edge.second] = true;
        total_weight += edge.first;
        for (auto edge : edges[edge.second]) pq.emplace(edge.first, edge.second);
    }
    return total_weight;
}