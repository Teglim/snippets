#include "template.h"

// >---------------- Doubling [Begin] ---------------->

struct Doubling {
    const int LOG = 60; // k ≤ 10^18
    int N;
    vector<vector<int>> table;

    // next[i]: i から 1 回遷移した先（-1 可）
    Doubling(const vector<int>& next) {
        N = next.size();

        table.assign(LOG, vector<int>(N, -1));
        table[0] = next;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < N; i++) {
                if (table[k - 1][i] == -1) continue;
                table[k][i] = table[k - 1][ table[k - 1][i] ];
            }
        }
    }

    // v から k 回遷移した先を返す（到達不可なら -1）
    int jump(int v, long long k) const {
        for (int i = 0; i < LOG; i++) {
            if (v == -1) break;
            if (k & (1LL << i)) {
                v = table[i][v];
            }
        }
        return v;
    }
};

// <---------------- Doubling [ End ] ----------------<


// >---------------- Doubling [Begin] ---------------->

const ll INF = 2e18;

// 行列積
vvll multiply(int N, const vvll& A, const vvll& B) {
    vvll C(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (A[i][k] == INF) continue;
            for (int j = 0; j < N; j++) {
                if (B[k][j] == INF) continue;
                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    return C;
}

// vvll res(N, vll(N, INF));
// for (int i = 0; i < N; i++) res[i][i] = 0;

// vvll base = C;
// while (K > 0) {
//     if (K & 1) res = multiply(N, res, base);
//     base = multiply(N, base, base);
//     K >>= 1;
// }

// <---------------- Doubling [ End ] ----------------<
