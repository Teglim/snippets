#include "template.h"

// >---------------- 尺取り法 [Begin] ---------------->

// A, B の要素間の最小 |差| を返す
int min_abs_diff(vll A, vll B) {
    sort(all(A));
    sort(all(B));

    int i = 0, j = 0;
    ll ans = INT64_MAX;

    while (i < (int)A.size() && j < (int)B.size()) {
        ans = min(ans, abs(A[i] - B[j]));
        if (A[i] < B[j]) i++;
        else j++;
    }
    return ans;
}

// <---------------- 尺取り法 [ End ] ----------------<



// >---------------- 貪欲尺取り法 [Begin] ---------------->

// (a, b) ペアの最大個数（a <= b, 各要素1回まで）
int max_pairs_leq(vll A, vll B) {
    sort(all(A));
    sort(all(B));

    int i = 0, j = 0;
    int cnt = 0;

    while (i < (int)A.size() && j < (int)B.size()) {
        if (A[i] <= B[j]) {
            cnt++;
            i++; j++;
        } else {
            j++;
        }
    }
    return cnt;
}

// <---------------- 貪欲尺取り法 [ End ] ----------------<


// >---------------- 尺取り法 [Begin] ---------------->
/* 和が K 以下になる連続部分列（検証済み） */

// 尺取り法
ll slid_wind(const vll& A, ll K) {
    int n = A.size();
    ll res = 0;
    int right = 0;

    ll sum = 0;
    for (int left = 0; left < n; left++) {
        while (right < n && sum + A[right] <= K) {
            sum += A[right];
            right++;
        }
        
        // right は条件を壊す最小
        res += max(0, right - left);
        sum -= A[left];
    }

    return res;
}

// <---------------- 尺取り法 [ End ] ----------------<


// >---------------- 尺取り法 [Begin] ---------------->
/* 和が K 以上になる連続部分列の個数 */

// 尺取り法
ll slid_wind(const vll& A, ll K) {
    int n = A.size();
    ll res = 0;
    int right = 0;

    ll sum = 0;
    for (int left = 0; left < n; left++) {
        while (right < n && sum + A[right] < K) {
            sum += A[right];
            right++;
        }
        
        // right は条件を壊す最小
        res += n - right;
        sum -= A[left];
    }

    return res;
}

// <---------------- 尺取り法 [ End ] ----------------<


// >---------------- 尺取り法 [Begin] ---------------->

// 尺取り法
ll slid_wind(const vll& A, ll K) {
    int n = A.size();
    ll res = 0;
    int right = 0;

    for (int left = 0; left < n; left++) {
        while (right < n && A[right] - A[left] <= K) {
            right++;
        }
        
        // right は条件を壊す最小
        res += max(0, right - left - 1);
    }

    return res;
}

// <---------------- 尺取り法 [ End ] ----------------<







// ------------------------ 以下は不完全なコードなので、使用は非推奨です。 ----------------------------


// >---------------- 尺取り法 [Begin] ---------------->

// 尺取り法
template <typename T>
int slid_wind(T &A, int x) {
    int res = 0;
    int n = A.size();

    int right = 0;
    for (int left = 0; left < n; left++) {
        /* right を進められるだけ進める */
        while (right < n && (/* right を 1 個進めたときに条件を満たす sum + A[right] <= x */)) {
            // sum += a[right];
            right++;
        }

        /* right は条件を満たす最大 */
        // res += (right - left);

        /* left を動かす準備 */
        // if (right == left) right++;
        // else sum -= a[left];
    }

    return res;
}

// <---------------- 尺取り法 [ End ] ----------------<


// >---------------- 尺取り法 [Begin] ---------------->

ll solve(vll &A, int x) {
    ll res = 0;
    int n = A.size();
    
    /* 区間の左端 left で場合分け */
    int right = 0;
    ll sum = 0;
    for (int left = 0; left < n; ++left) {
        /* sum に a[right] を加えても大丈夫なら right を動かす */
        while (right < n && sum + A[right] <= x) {
            sum += A[right];
            ++right;
        }
        
        /* left を固定したときの有効区間数 */
        res += (right - left);
        
        /* left をインクリメントする準備 */
        if (right == left) ++right; // right が left に重なったら right も動かす
        else sum -= A[left]; // left のみがインクリメントされるので sum から a[left] を引く
    }

    return res;
}

// <---------------- 尺取り法 [ End ] ----------------<
