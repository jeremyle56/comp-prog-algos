typedef pair<pt, pt> seg;

bool collinear(seg ab, seg cd) {  // all four points collinear
    pt a = ab.first, b = ab.second, c = cd.first, d = cd.second;
    return zero(cross(b - a, c - a)) && zero(cross(b - a, d - a));
}

double sq(double t) { return t * t; }

double dist(pt p, pt q) { return sqrt(sq(p.x - q.x) + sq(p.y - q.y)); }

bool intersect(seg ab, seg cd) {
    pt a = ab.first, b = ab.second, c = cd.first, d = cd.second;

    if (collinear(ab, cd)) {
        double maxDist =
            max({dist(a, b), dist(a, c), dist(a, d), dist(b, c), dist(b, d), dist(c, d)});
        return maxDist < dist(a, b) + dist(c, d) + EPS;
    }

    return ccw(a, b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c, d, b);
}