#include "template.h"

// >---------------- Union Find [Begin] ---------------->

class UnionFind {
    vector<int> par, rank, siz;
    int comp;

   public:
    // 初期化
    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1), comp(n) {}

    // 根を求める
    int root(int x) {
        if (par[x] == -1) return x;        // x が根の場合は x を返す
        else return par[x] = root(par[x]); // 経路圧縮
    }

    // x と y が同じグループに属するか (= 根が一致するか)
    bool issame(int x, int y) { return root(x) == root(y); }

    // x を含むグループと y を含むグループを併合する
    bool unite(int x, int y) {
        int rx = root(x), ry = root(y); // x 側と y 側の根を取得する
        if (rx == ry) return false;     // すでに同じグループのときは何もしない
        // union by rank
        if (rank[rx] < rank[ry]) swap(rx, ry); // ry 側の rank が小さくなるようにする
        par[ry] = rx;                          // ry を rx の子とする
        if (rank[rx] == rank[ry]) rank[rx]++;  // rx 側の rank を調整する
        siz[rx] += siz[ry];                    // rx 側の siz を調整する
        comp--; // 成分が一つ減る
        return true;
    }

    // x を含む根付き木のサイズを求める
    int size(int x) { return siz[root(x)]; }

    // 連結成分数
    int components() { return comp; }
};

// <---------------- Union Find [ End ] ----------------<

// >---------------- Kruskal [Begin] ---------------->

// 頂点a, bをつなぐコストcostの（無向）辺
struct Edge {
    int a, b, cost;

    // コストの大小で順序定義
    bool operator<(const Edge& o) const { return cost < o.cost; }
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph {
    int n;            // 頂点数
    vector<Edge> es;  // 辺集合

    // クラスカル法で無向最小全域木のコストの和を計算する
    // グラフが非連結のときは最小全域森のコストの和となる
    int kruskal() {
        // コストが小さい順にソート
        sort(es.begin(), es.end());

        UnionFind uf(n);
        int min_cost = 0;

        for (int ei = 0; ei < (int)es.size(); ei++) {
            Edge& e = es[ei];
            if (!uf.issame(e.a, e.b)) {
                // 辺を追加しても閉路ができないなら、その辺を採用する
                min_cost += e.cost;
                uf.unite(e.a, e.b);
            }
        }

        return min_cost;
    }
};

// 標準入力からグラフを読み込む
Graph input_graph() {
    Graph g;
    int m;
    cin >> g.n >> m;
    for (int i = 0; i < m; i++) {
        Edge e;
        int a, b;
        cin >> a >> b >> e.cost;
        e.a = --a;
        e.b = --b;
        g.es.push_back(e);
    }
    return g;
}

// <---------------- Kruskal [ End ] ----------------<

int main() {
    Graph g = input_graph();
    cout << g.kruskal() << endl;
}
