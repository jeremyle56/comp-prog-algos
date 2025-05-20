const double EPS = 1e-8;
typedef pair<double, double> pt;
#define x first
#define y second

pt operator-(pt a, pt b) { return pt(a.x - b.x, a.y - b.y); }

bool zero(double x) { return fabs(x) <= EPS; }

double cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

// true if left or straight
// sometimes useful to instead return an int
// -1, 0 or 1: the sign of the cross product
bool ccw(pt a, pt b, pt c) { return cross(b - a, c - a) >= 0; }