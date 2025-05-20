int binarysearch(function<bool(int)> f) {
    int lo = 0, hi = 100000, bestSoFar = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid)) {
            bestSoFar = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    return bestSoFar;
}