#include "template.h"

int main() {

    // >---------------- DFS [Begin] ---------------->
    /* グラフの連結性判定 */

    int N, M;
    cin >> N >> M;

    vvi graph(N);

    while (M--) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<bool> visited(N);

    auto dfs = [&](int sv) {
        stack<int> st;
        st.push(sv);
        visited[sv] = true;

        while (!st.empty()) {
            int v = st.top(); st.pop();
            for (int nv : graph[v]) {
                if (!visited[nv]) {
                    visited[nv] = true;
                    st.push(nv);
                }
            }
        }
    };

    // dfs(0);

    // <---------------- DFS [ End ] ----------------<


    // >---------------- DFS [Begin] ---------------->
    /* DFS */

    auto dfs = [&](auto&& self, int v) -> void {
        for (int nv : graph[v]) {
            self(self, nv);
        }
    };

    // dfs(dfs, root);

    // <---------------- DFS [ End ] ----------------<


    // >---------------- DFS [Begin] ---------------->
    /* ツリーの探索 */

    int N;
    cin >> N;

    vvi tree(N);

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    auto dfs = [&](auto&& self, int v, int p) -> void {
        for (int nv : tree[v]) {
            if (nv == p) continue;
            self(self, nv, v);
        }
    };

    // dfs(dfs, root, -1);

    // <---------------- DFS [ End ] ----------------<


    // >---------------- DFS [Begin] ---------------->
    /* ツリーの探索。自身を含む部分木サイズ */

    int N;
    cin >> N;

    vvi tree(N);

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    vi subtree_size(N);

    auto dfs = [&](auto&& self, int v, int p) -> int {
        int cnt = 1;

        for (int nv : tree[v]) {
            if (nv == p) continue;
            cnt += self(self, nv, v);
        }

        subtree_size[v] = cnt;
        return cnt;
    };

    // dfs(dfs, 0, -1);

    // <---------------- DFS [End] ----------------<

}

// >---------------- DFS [Begin] ---------------->

// 無向グラフの各連結成分について「ノード数・辺数」を返す
v<pii> connected_components_stats(const unordered_map<int, vi>& graph) {
    unordered_set<int> visited;
    v<pii> res;

    for (const auto& [start, _] : graph) {
        if (visited.count(start)) continue;

        int node_count = 0;
        int edge_count = 0; // 無向なので2倍で数える

        stack<int> st;
        st.push(start); visited.insert(start);

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            node_count++;

            for (auto v : graph.at(u)) {
                edge_count++;
                if (!visited.count(v)) {
                    st.push(v); visited.insert(v);
                }
            }
        }

        res.emplace_back(node_count, edge_count / 2);
    }

    return res;
}

// <---------------- DFS [ End ] ----------------<


// >---------------- DFS [Begin] ---------------->

vector<int> DFS(int start, const vvi &graph) {
    int N = graph.size();
    vector<int> dist(N, -1);
    dist[start] = 0;
    stack<int> st({start});
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        for (auto nv: graph[v]) {
            if (dist[nv] == -1) {
                st.push(nv);
                dist[nv] = dist[v] + 1;
            }
        }
    }
    return dist;
}

// <---------------- DFS [ End ] ----------------<
