#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> edge;  // (distance, vertex)
const int N = 100100;

vector<edge> edges[N];
ll dist[N];
bool seen[N];
priority_queue<edge, vector<edge>, greater<edge>> pq;

void dijkstra(int s) {
    fill(seen, seen + N, false);
    pq.push(edge(0, s));
    while (!pq.empty()) {
        edge cur = pq.top();
        pq.pop();
        int v = cur.second;
        ll d = cur.first;
        if (seen[v]) continue;

        dist[v] = d;
        seen[v] = true;

        for (edge nxt : edges[v]) {
            int u = nxt.second;
            ll weight = nxt.first;
            if (!seen[u]) pq.push(edge(d + weight, u));
        }
    }
}