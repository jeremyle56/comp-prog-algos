bool isprime(int x) {
    if (x < 2) return false;

    for (int f = 2; f * f <= x; f++)
        if (x % f == 0) return false;

    return true;
}