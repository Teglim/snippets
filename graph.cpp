#include "template.h"

// >---------------- graph [Begin] ---------------->
// 有向重み付きグラフ（負辺あり）
// 0 -> N-1 への "最長路"
// Bellman–Ford

const ll INF = (1LL << 60);
const ll NINF = -INF;

ll longest_path(int N, v<tuple<int, int, ll>> &edges) {
    vvi g(N);
    for (auto &[a, b, c] : edges) {
        g[a].push_back(b);
    }

    vll dist(N, NINF);
    dist[0] = 0;

    for (int i = 0; i < N - 1; i++) {
        for (auto &[a, b, c] : edges) {
            if (dist[a] == NINF) continue;
            dist[b] = max(dist[b], dist[a] + c);
        }
    }

    vi upd;
    for (auto &[a, b, c] : edges) {
        if (dist[a] == NINF) continue;
        if (dist[b] < dist[a] + c) {
            upd.push_back(b);
        }
    }

    vi vis(N, 0);
    queue<int> q;
    for (int x : upd) {
        if (!vis[x]) {
            vis[x] = 1;
            q.push(x);
        }
    }

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int to : g[v]) {
            if (!vis[to]) {
                vis[to] = 1;
                q.push(to);
            }
        }
    }

    if (vis[N - 1]) return INF;
    if (dist[N - 1] == NINF) return NINF;
    return dist[N - 1];
}

// <---------------- graph [ End ] ----------------<


// >---------------- graph [Begin] ---------------->
// 有向重み付きグラフ（負辺あり）
// 0 -> N-1 への "最短路"
// Bellman–Ford

const ll INF = (1LL << 60);
const ll NINF = -INF;

ll shortest_path(int N, v<tuple<int, int, ll>> &edges) {
    vvi g(N);
    for (auto &[a, b, c] : edges) {
        g[a].push_back(b);
    }

    vll dist(N, INF);
    dist[0] = 0;

    for (int i = 0; i < N - 1; i++) {
        for (auto &[a, b, c] : edges) {
            if (dist[a] == INF) continue;
            dist[b] = min(dist[b], dist[a] + c);
        }
    }

    vi upd;
    for (auto &[a, b, c] : edges) {
        if (dist[a] == INF) continue;
        if (dist[b] > dist[a] + c) {
            upd.push_back(b);
        }
    }

    vi vis(N, 0);
    queue<int> q;
    for (int x : upd) {
        if (!vis[x]) {
            vis[x] = 1;
            q.push(x);
        }
    }

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int to : g[v]) {
            if (!vis[to]) {
                vis[to] = 1;
                q.push(to);
            }
        }
    }

    if (vis[N - 1]) return NINF;
    if (dist[N - 1] == INF) return INF;
    return dist[N - 1];
}

// <---------------- graph [ End ] ----------------<

