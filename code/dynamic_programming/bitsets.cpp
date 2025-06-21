// for all sets
for (int set = 0; set < (1 << n); ++set) {
    // for all subsets of that set
    for (int subset = set; subset; subset = (subset - 1) & set) {
        // do something with the subset
    }
}

// Alternatively - also can replace (1 << n) with pow(2, n)
for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
            // do something with A[j]
        }
    }
}