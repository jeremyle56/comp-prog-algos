// for all sets
for (int set = 0; set < (1 << n); set++) {
    // for all subsets of that set
    for (int subset = set; subset; subset = (subset - 1) & set) {
        // do something with the subset
    }
}