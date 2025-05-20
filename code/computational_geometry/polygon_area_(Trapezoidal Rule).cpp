double area(vector<pt> pts) {
    double res = 0;
    int n = pts.size();
    for (int i = 0; i < n; i++) {
        res += (pts[i].y + pts[(i + 1) % n].y) * (pts[(i + 1) % n].x - pts[i].x);
    }
    return res / 2.0;
}