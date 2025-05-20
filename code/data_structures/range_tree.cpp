const int N = 100100;
// 2^17 = 131,072
int tree[1 << 18];

int n;

int query(int qL, int qR, int i = 1, int cL = 0, int cR = n) {
    if (cL == qL && cR == qR) return tree[i];
    int mid = (cL + cR) / 2;
    int ans = 0;
    if (qL < mid) ans += query(qL, min(qR, mid), i * 2, cL, mid);
    if (qR > mid) ans += query(max(qL, mid), qR, i * 2 + 1, mid, cR);
    return ans;
}

void update(int p, int v, int i = 1, int cL = 0, int cR = n) {
    if (cR - cL == 1) {
        tree[i] = v;
        return;
    }

    int mid = (cL + cR) / 2;
    if (p < mid) update(p, v, i * 2, cL, mid);
    else update(p, v, i * 2 + 1, mid, cR);
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void debug(int i = 1, int cL = 0, int cR = n) {
    cerr << "tree[" << cL << "," << cR << ") = " << tree[i];

    if (cR - cL > 1) {
        int mid = (cL + cR) / 2;
        debug(i * 2, cL, mid);
        debug(i * 2 + 1, mid, cR);
    }
}