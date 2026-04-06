#include "template.h"

// >---------------- DP [Begin] ---------------->
/* 各品物の重さ weight[i]、価値 value[i]、重さ制限 W */

// 0/1ナップザックDP
ll knapsack_01(const vll& weight, const vll& value, int W) {
    int n = weight.size();
    vll dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    return dp[W];
}

// <---------------- DP [ End ] ----------------<


// >---------------- DP [Begin] ---------------->
/* 各品物の重さ weight[i]、価値 value[i]、重さ制限 W */

// dp[v] = 価値 v を得る重さの最小値
// 0/1ナップザックDP、価値 DP
ll knapsack_01(const vll& weight, const vll& value, ll W) {
    int n = weight.size();
    ll Vsum = accumulate(all(value), 0LL);

    const ll INF = (1LL << 60);
    vll dp(Vsum + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (ll v = Vsum; v >= value[i]; v--) {
            dp[v] = min(dp[v], dp[v - value[i]] + weight[i]);
        }
    }

    ll ans = 0;
    for (ll v = 0; v <= Vsum; v++) {
        if (dp[v] <= W) ans = max(ans, v);
    }
    return ans;
}

// <---------------- DP [ End ] ----------------<

// >---------------- DP [Begin] ---------------->
// 桁DPの例 ABC135 : D - Digits Parade

const ll MOD = 1'000'000'007;

void solve() {
    string S;
    cin >> S;

    int N = S.size();
    vvll dp(N + 1, vll(13, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 13; j++) {
            if (S[i] == '?') {
                for (int k = 0; k < 10; k++) {
                    int nj = (j * 10 + k) % 13;
                    dp[i + 1][nj] += dp[i][j];
                    dp[i + 1][nj] %= MOD;
                }
            } else {
                int k = S[i] - '0';
                int nj = (j * 10 + k) % 13;
                dp[i + 1][nj] += dp[i][j];
                dp[i + 1][nj] %= MOD;
            }
        }
    }

    cout << dp[N][5] << '\n';
}

// <---------------- DP [ End ] ----------------<
