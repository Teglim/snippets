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

    // x と y が同じグループに属するか
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

    // x を含むグループのサイズを求める
    int size(int x) { return siz[root(x)]; }

    // 連結成分数
    int components() { return comp; }
};

// <---------------- Union Find [ End ] ----------------<
