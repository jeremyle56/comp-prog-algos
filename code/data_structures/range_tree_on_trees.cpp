vector<int> children[N];

int indexInRangeTree[N], startRange[N], endRange[N];
int totId;

void compute_tree_ranges(int v) {
    indexInRangeTree[v] = startRange[v] = totId++;
    for (int w : children[v]) compute_tree_ranges(w);
    endRange[v] = totId;
}

void update_node(int id, int v) { update(indexInRangeTree[id], v); }
long long query_subtree(int id) { return query(startRange[id], endRange[id]); }