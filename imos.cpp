#include "template.h"

// >---------------- imos_2D [Begin] ---------------->

// 0-index
class Imos2D {
private:
    int N, M;
    vvll diff;   // 差分配列
    vvll grid;   // 累積後の配列
    bool built = false;

public:
    // 初期化
    Imos2D(int n, int m) : N(n), M(m) {
        diff.assign(N + 1, vll(M + 1, 0));
        grid.assign(N, vll(M, 0));
    }

    // 矩形 [x1, y1] × [x2, y2] に +1（閉区間）
    void add(int x1, int y1, int x2, int y2) {
        add(x1, y1, x2, y2, 1);
    }

    // 矩形 [x1, y1] × [x2, y2] に +k（閉区間）
    void add(int x1, int y1, int x2, int y2, ll k) {
        assert(0 <= x1 && x1 <= x2 && x2 < N);
        assert(0 <= y1 && y1 <= y2 && y2 < M);
        built = false;

        diff[x1][y1] += k;
        diff[x1][y2 + 1] -= k;
        diff[x2 + 1][y1] -= k;
        diff[x2 + 1][y2 + 1] += k;
    }

    // 二次元累積和
    void build() {
        // 横方向
        for (int i = 0; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }
        // 縦方向
        for (int j = 0; j <= M; j++) {
            for (int i = 1; i <= N; i++) {
                diff[i][j] += diff[i - 1][j];
            }
        }
        // grid にコピー
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                grid[i][j] = diff[i][j];
            }
        }
        built = true;
    }

    // k がいくつあるか
    int count(ll k) const {
        assert(built);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == k) cnt++;
            }
        }
        return cnt;
    }

    // 値取得
    ll get(int x, int y) const {
        assert(built);
        return grid[x][y];
    }

    // グリッド取得
    const vvll& get_grid() const {
        assert(built);
        return grid;
    }
};

// <---------------- imos_2D [ End ] ----------------<


// >---------------- imos_1D [Begin] ---------------->

// 0-index
class Imos1D {
private:
    int N;
    vll diff;   // 差分配列
    vll arr;    // 累積後の配列
    bool built = false;

public:
    // 初期化
    Imos1D(int n) : N(n) {
        diff.assign(N + 1, 0);
        arr.assign(N, 0);
    }

    // 区間 [l, r] に +1（閉区間）
    void add(int l, int r) {
        add(l, r, 1);
    }

    // 区間 [l, r] に +k（閉区間）
    void add(int l, int r, ll k) {
        assert(0 <= l && l <= r && r < N);
        built = false;

        diff[l] += k;
        diff[r + 1] -= k;
    }

    // 累積和
    void build() {
        ll cur = 0;
        for (int i = 0; i < N; i++) {
            cur += diff[i];
            arr[i] = cur;
        }
        built = true;
    }

    // k がいくつあるか
    int count(ll k) const {
        assert(built);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == k) cnt++;
        }
        return cnt;
    }

    // 値取得
    ll get(int i) const {
        assert(built);
        return arr[i];
    }

    // 配列取得
    const vll& get_array() const {
        assert(built);
        return arr;
    }
};

// <---------------- imos_1D [ End ] ----------------<
