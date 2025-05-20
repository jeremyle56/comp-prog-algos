bool collinear(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    return (b.second - a.second) * (c.first - b.first) ==
           (c.second - b.second) * (b.first - a.first);
}