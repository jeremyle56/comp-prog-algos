for (int u = 0; u < n; ++u)
    for (int v = 0; v < n; ++v) dist[u][v] = INF;

for (edge e : edges) dist[e.u][e.v] = e.w;

for (int u = 0; u < n; ++u) dist[u][u] = 0;

for (int i = 0; i < n; i++)
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++) dist[u][v] = min(dist[u][v], dist[u][i] + dist[i][v]);