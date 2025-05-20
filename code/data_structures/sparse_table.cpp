const int N = 100000;
const int LOGN = 18;

int a[N];
// sparseTable[l][i] = max a[i..i+2^l)
int sparseTable[LOGN][N];

void precomp(int n) {
    // level 0 is the array itself
    for (int i = 0; i < n; i++) sparseTable[0][i] = a[i];

    for (int l = 1; l < LOGN; l++) {  // inner loop does nothing if 2^l > n
        int w = 1 << (l - 1);         // 2^(l-1)

        // a[i,i+2w) is made up of a[i,i+w) and a[i+w,i+2w)
        for (int i = 0; i + 2 * w <= n; i++)
            sparseTable[l][i] = max(sparseTable[l - 1][i], sparseTable[l - 1][i + w]);
    }
}