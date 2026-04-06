#include "template.h"

// >---------------- 2D prefix_sum [Begin] ---------------->

struct PrefixSum2D {
    int H, W;
    vvll s;

    // a: H×W の 2D 配列（0-indexed）
    PrefixSum2D(const vvll& a) {
        H = a.size();
        W = a[0].size();
        s.assign(H + 1, vll(W + 1, 0));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                s[i + 1][j + 1] =
                    s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
            }
        }
    }

    // 長方形 [x1, x2) × [y1, y2) の和（0-indexed, 半開区間）
    ll rect_sum(int x1, int y1, int x2, int y2) const {
        return s[x2][y2]
             - s[x1][y2]
             - s[x2][y1]
             + s[x1][y1];
    }
};

// <---------------- 2D prefix_sum [ End ] ----------------<


// >---------------- 2D prefix_sum [Begin] ---------------->

struct PrefixSum2D {
    int H, W;
    vvll s;

    // a: H×W の 2D 配列（0-indexed）
    PrefixSum2D(const vvll& a) {
        H = a.size();
        W = a[0].size();
        s.assign(H + 1, vll(W + 1, 0));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                s[i + 1][j + 1] =
                    s[i][j + 1]
                  + s[i + 1][j]
                  - s[i][j]
                  + a[i][j];
            }
        }
    }

    // 長方形 [x1, x2] × [y1, y2] の和（0-indexed, 閉区間）
    ll rect_sum(int x1, int y1, int x2, int y2) const {
        return s[x2 + 1][y2 + 1]
             - s[x1][y2 + 1]
             - s[x2 + 1][y1]
             + s[x1][y1];
    }
};

// <---------------- 2D prefix_sum [ End ] ----------------<


// >---------------- 1D prefix_sum [Begin] ---------------->

struct PrefixSum {
    int N;
    vll s;  // s[i] = [0, i) の和

    // a: 0-indexed 配列
    PrefixSum(const vll& a) {
        N = a.size();
        s.assign(N + 1, 0);

        for (int i = 0; i < N; i++) {
            s[i + 1] = s[i] + a[i];
        }
    }

    // 閉区間 [l, r] の和（0-indexed, 閉区間）
    ll range_sum(int l, int r) const {
        return s[r + 1] - s[l];
    }
};

// <---------------- 1D prefix_sum [ End ] ----------------<

    // vll pref(N + 1);
    // for (int i = 0; i < N; i++) {
    //     pref[i + 1] = (pref[i] + A[i]) % K;
    // }
