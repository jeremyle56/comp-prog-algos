vector<pt> half_hull(vector<pt> pts) {
    vector<pt> res;
    for (int i = 0; i < pts.size(); i++) {
        // ccw means we have a left turn; we don't want that
        while (res.size() >= 2 && ccw(pts[i], res[res.size() - 1], res[res.size() - 2])) {
            res.pop_back();
        }
        res.push_back(pts[i]);
    }
    return res;
}

vector<pt> convex_hull(vector<pt> pts) {
    sort(pts.begin(), pts.end());
    vector<pt> top = half_hull(pts);

    reverse(pts.begin(), pts.end());
    vector<pt> bottom = half_hull(pts);

    top.pop_back();
    bottom.pop_back();
    vector<pt> res(top.begin(), top.end());
    res.insert(res.end(), bottom.begin(), bottom.end());
    return res;
}