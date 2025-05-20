const int N = 200010;
int parent[N];
int subtree_size[N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        subtree_size[i] = 1;
    }
}

int root(int x) { return parent[x] == x ? x : parent[x] = root(parent[x]); }

void join(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (subtree_size[y] < subtree_size[x]) swap(x, y);
    parent[x] = y;
    subtree_size[y] += subtree_size[x];
}