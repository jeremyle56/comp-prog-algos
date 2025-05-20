vector<int> primefactorize(int x) {
    vector<int> factors;
    for (int f = 2; f * f <= x; f++)
        while (x % f == 0) {
            factors.push_back(f);
            x /= f;
        }

    if (x != 1) factors.push_back(x);
    return factors;
}