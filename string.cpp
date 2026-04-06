#include "template.h"

// >---------------- substring [Begin] ---------------->

/* 文字列を高速に切り出せる数列に変換して比較します */
struct RollingHash {
    static const ll MOD1 = 1000000007;
    static const ll MOD2 = 1000000009;
    static const ll BASE = 911382323;

    ll n;
    vll h1, h2, p1, p2;

    RollingHash(const string& s) {
        n = s.size();
        h1.resize(n + 1);
        h2.resize(n + 1);
        p1.resize(n + 1);
        p2.resize(n + 1);
        p1[0] = p2[0] = 1;

        for (ll i = 0; i < n; i++) {
            ll v = s[i] - 'a' + 1;
            h1[i + 1] = (h1[i] * BASE + v) % MOD1;
            h2[i + 1] = (h2[i] * BASE + v) % MOD2;
            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;
        }
    }

    // hash of S[l..r], 1-indexed
    pll get(ll l, ll r) const {
        ll x1 = (h1[r] - h1[l - 1] * p1[r - l + 1]) % MOD1;
        if (x1 < 0) x1 += MOD1;
        ll x2 = (h2[r] - h2[l - 1] * p2[r - l + 1]) % MOD2;
        if (x2 < 0) x2 += MOD2;
        return {x1, x2};
    }
};

// <---------------- substring [ End ] ----------------<
