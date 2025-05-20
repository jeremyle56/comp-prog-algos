const int N = 1e6 + 5;

vector<int> edges[N];

int par[N];               // Parent. -1 for the root.
vector<int> children[N];  // Your children in the tree.
int size[N];              // As an example: size of each subtree.

void constructTree(int c, int cPar = -1) {
    par[c] = cPar;
    size[c] = 1;
    for (int nxt : edges[c]) {
        if (nxt == par[c]) continue;
        constructTree(nxt, c);
        children[c].push_back(nxt);
        size[c] += size[nxt];
    }
}