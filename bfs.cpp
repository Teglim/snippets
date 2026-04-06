#include "template.h"

// >---------------- BFS [Begin] ---------------->

vi bfs(int start, const vvi &graph) {
    int N = graph.size();
    vi dist(N, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (dist[v] != -1) continue; // 到達済み

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist;
}

// <---------------- BFS [ End ] ----------------<


// >---------------- BFS [Begin] ---------------->
/* 迷路探索 */

const vi dx = {1, 0, -1, 0};
const vi dy = {0, 1, 0, -1};

vvi bfs_maze(pii start, const vs &field) {
    int R = field.size();
    int C = field[0].size();
    vvi dist(R, vi(C, -1));
    queue<pii> q;
    auto [r, c] = start;
    dist[r][c] = 0;
    q.push(start);
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (field[nr][nc] == '#' || dist[nr][nc] != -1) continue;
            
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    return dist;
}

// <---------------- BFS [ End ] ----------------<


// >---------------- 0-1 BFS [Begin] ---------------->
/* 迷路探索 ABC 213 : E - Stronger Takahashi */

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

vvi bfs_maze(pii start, const vector<string> &field) {
    int R = field.size();
    int C = field[0].size();

    const int INF = (1 << 30);
    vvi dist(R, vi(C, INF));
    deque<pii> q;
    auto [r, c] = start;
    dist[r][c] = 0;
    q.push_front(start);
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop_front();

        for (int dir = 0; dir < 4; ++dir) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (field[nr][nc] == '#') continue;
            if (dist[nr][nc] <= dist[r][c]) continue;

            dist[nr][nc] = dist[r][c];
            q.push_front({nr, nc});
        }

        for (int nr = r - 2; nr <= r + 2; ++nr) {
            for (int nc = c - 2; nc <= c + 2; ++nc) {
                if (abs(nr - r) + abs(nc - c) == 4) continue;
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if (dist[nr][nc] <= dist[r][c] + 1) continue;

                dist[nr][nc] = dist[r][c] + 1;
                q.push_back({nr, nc});
            }
        }
    }
    return dist;
}

// <---------------- BFS [ End ] ----------------<
