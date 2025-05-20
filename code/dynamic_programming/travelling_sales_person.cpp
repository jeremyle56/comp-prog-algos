const int N = 20;
const int INF = 1e9;
int n, adj[N][N];   // assume this is given.
int dp[1 << N][N];  // dp[x][i] is the shortest 0->i path visiting set bits of x

int tsp(void) {
    for (int mask = 0; mask < (1 << n); mask++)
        for (int city = 0; city < n; city++) dp[mask][city] = INF;
    dp[1][0] = 0;  // 1 represents seen set {0}

    int ans = INF;
    for (int mask = 1; mask < (1 << n); mask++)  // for every subset of cities seen so far
        for (int cur = 0; cur < n; cur++)
            if (mask & (1 << cur)) {       // cur must be one of the cities seen so far
                int cdp = dp[mask][cur];   // distance travelled so far
                if (mask == (1 << n) - 1)  // seen all cities, return to 0
                    // unlike the traditional TSP, we don't have to add adj[cur][0] to account for
                    // an edge back to vertex 0
                    ans = min(ans, cdp);
                for (int nxt = 0; nxt < n; nxt++)
                    if (!(mask & (1 << nxt)))  // try going to a new city
                        // new seen set is mask union {nxt}, and we will be at nxt
                        // distance incurred to get to this state is now no worse than
                        // cdp (current distance incurred) + edge from cur to nxt
                        dp[mask | (1 << nxt)][nxt] =
                            min(dp[mask | (1 << nxt)][nxt], cdp + adj[cur][nxt]);
            }
    return ans;
}