#include "template.h"

// >---------------- DP [Begin] ---------------->

// 編集距離
int edit_dist(const string& S, const string& T) {
    int N = S.size();
    int M = T.size();
    vvi dp(N + 1, vi(M + 1));

    for (int i = 0; i <= N; i++) dp[i][0] = i;
    for (int j = 0; j <= M; j++) dp[0][j] = j;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int cost = (S[i - 1] != T[j - 1]);
            dp[i][j] = min({
                dp[i - 1][j] + 1,       // 削除
                dp[i][j - 1] + 1,       // 挿入
                dp[i - 1][j - 1] + cost // 置換
            });
        }
    }
    return dp[N][M];
}

// <---------------- DP [ End ] ----------------<


// >---------------- DP [Begin] ---------------->

// 最長共通部分列
int LCS(const string& S, const string& T) {
    int N = S.size();
    int M = T.size();
    vvi dp(N + 1, vi(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[N][M];
}

// 最長回文部分列
int LPS(const string& S) {
    string R = S;
    reverse(all(R));
    return LCS(S, R);
}

// <---------------- DP [ End ] ----------------<


// >---------------- DP [Begin] ---------------->

// 最長共通部分列（本体を返す）
string LCS_string(const string& S, const string& T) {
    int N = S.size();
    int M = T.size();
    vvi dp(N + 1, vi(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 復元
    string res;
    int i = N, j = M;

    while (i > 0 && j > 0) {
        if (S[i - 1] == T[j - 1]) {
            res.push_back(S[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(all(res));
    return res;
}

// 最長回文部分列（本体）
string LPS_string(const string& S) {
    string R = S;
    reverse(all(R));
    return LCS_string(S, R);
}

// <---------------- DP [ End ] ----------------<


// >---------------- DP / binary search [Begin] ---------------->

// 最長増加部分列
int LIS_len(const vector<int>& a) {
    vector<int> dp;
    for (int x : a) {
        auto it = lower_bound(all(dp), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return (int)dp.size();
}

// <---------------- DP / binary search [ End ] ----------------<


// >---------------- DP / binary search [Begin] ---------------->

// i で終わる LIS
vector<int> LIS(const vector<int>& a) {
    int n = a.size();
    vector<int> dp;
    vector<int> res(n);

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        int pos = it - dp.begin();

        if (it == dp.end()) dp.push_back(a[i]);
        else *it = a[i];

        res[i] = pos + 1; // i で終わる LIS 長
    }
    return res;
}

// <---------------- DP / binary search [ End ] ----------------<


// 以下は vector<int> での実装です。


// >---------------- DP [Begin] ---------------->

// 編集距離
int edit_dist(const vector<int>& S, const vector<int>& T) {
    int N = S.size();
    int M = T.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));

    for (int i = 0; i <= N; i++) dp[i][0] = i;
    for (int j = 0; j <= M; j++) dp[0][j] = j;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int cost = (S[i - 1] != T[j - 1]);
            dp[i][j] = min({
                dp[i - 1][j] + 1,       // 削除
                dp[i][j - 1] + 1,       // 挿入
                dp[i - 1][j - 1] + cost // 置換
            });
        }
    }
    return dp[N][M];
}

// <---------------- DP [ End ] ----------------<
