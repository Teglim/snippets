#include "template.h"

// >---------------- dijkstra [Begin] ---------------->

const ll INF = (1LL << 60);

// n: 頂点数
// graph[u]: (v, w) の配列。u-v 間に重み w の無向辺
vector<ll> dijkstra(int start, vector<vector<pair<int, ll>>> &graph) {
    int n = graph.size();
    vector<ll> dist(n, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) dist[i] = -1;
    }

    return dist;
}

// <---------------- dijkstra [ End ] ----------------<


// >---------------- warshall_floyd [Begin] ---------------->

const ll INF = (1LL << 60);

// graph[u]: (v, w) の配列。u-v 間に重み w の無向辺
// 戻り値: dist[i][j] = i から j への最短距離（到達不可は -1）
vvll warshall_floyd(vv<pll> &graph) {
    int n = graph.size();
    vvll dist(n, vll(n, INF));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (auto [to, w] : graph[i]) {
            dist[i][to] = min(dist[i][to], w);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (dist[k][j] == INF) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) dist[i][j] = -1;
        }
    }

    return dist;
}

// <---------------- warshall_floyd [ End ] ----------------<
