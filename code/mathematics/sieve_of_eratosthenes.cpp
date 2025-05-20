bool marked[N + 1];
vector<int> primefactorization[N + 1];

for (int i = 2; i <= N; i++) {
    if (!marked[i]) {
        primefactorization[i].push_back(i);
        for (int j = 2 * i; j <= N; j += i) {
            marked[j] = true;
            int tmp = j;
            while (tmp % i == 0) {
                primefactorization[j].push_back(i);
                tmp /= i;
            }
        }
    }
}