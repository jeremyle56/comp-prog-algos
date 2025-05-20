typedef pair<double, double> pt;

struct line {
    double a, b, c;
};

struct half_plane {
    line l;
    bool neg;  // is the inequality <= or >=
};

const double EPS = 1e-8;

pt intersect(line f, line g) {
    double d = f.a * g.b - f.b * g.a;
    double y = (f.a * g.c - f.c * g.a) / (f.b * g.a - f.a * g.b);
    double x = (f.c * g.b - f.b * g.c) / (f.b * g.a - f.a * g.b);
    return pt(x, y);
}

bool in_half_plane(half_plane hp, pt q) {
    if (hp.neg) return hp.l.a * q.x + hp.l.b * q.y + hp.l.c <= EPS;
    else return hp.l.a * q.x + hp.l.b * q.y + hp.l.c >= -EPS;
}

vector<pt> intersect_half_planes(vector<half_plane> half_planes) {
    int n = half_planes.size();
    vector<pt> pts;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pt p = intersect(half_planes[i].l, half_planes[j].l);
            bool fail = false;
            for (int k = 0; k < n; k++)
                if (!in_half_plane(half_planes[k], p)) fail = true;
            if (!fail) pts.push_back(p);
        }
    }

    vector<pt> res = pts;
    if (pts.size() > 2) pts = convex_hull(res);
    return pts;
}