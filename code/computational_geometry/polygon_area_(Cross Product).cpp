double area(vector<pt> pts) {
    double res = 0;
    int n = pts.size();
    for (int i = 1; i < n - 1; i++) {
        // i = 0 and i = n-1 are degenerate triangles, OK to omit
        // e.g. if i = 1 is ABC, and i = 2 is ACD, then i = 0 is AAB
        res += cross(pts[i] - pts[0], pts[i + 1] - pts[0]);
    }
    return res / 2.0;
}