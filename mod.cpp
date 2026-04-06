#include "template.h"

// >---------------- mod [Begin] ---------------->

const ll MOD = 998'244'353;
// const ll MOD = 1'000'000'007;

// x^n を MOD で割った余り
ll mod_pow(ll x, ll n) {
	x %= MOD;
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

// MOD での x の逆元
ll mod_inv(ll x) {
    return mod_pow(x, MOD - 2);
}

// nCr 二項係数
ll mod_comb(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);

    ll num = 1, den = 1;
    for (ll i = 1; i <= r; i++) {
        num = num * (n - r + i) % MOD;
        den = den * i % MOD;
    }
    return num * mod_inv(den) % MOD;
}

// <---------------- mod [ End ] ----------------<

// >---------------- mod [Begin] ---------------->
// 任意 MOD

// x^n を M で割った余り
ll m_pow(ll x, ll n, ll M) {
	x %= M;
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % M;
        x = x * x % M;
        n >>= 1;
    }
    return res;
}

// 拡張ユークリッドの互除法
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

ll m_inv(ll a, ll M) {
    ll x, y;
    extgcd(a, M, x, y);
    x %= M;
    if (x < 0) x += M;
    return x;
}

// <---------------- mod [ End ] ----------------<

main () {

    // >---------------- comb, perm の前計算 [Begin] ---------------->
    // n C r の n の上限
    int MX = 101010;

    vll fact(MX), ifact(MX);

    fact[0] = 1;
    for (int i = 1; i < MX; i++) fact[i] = fact[i - 1] * i % MOD;

    ifact[MX - 1] = mod_inv(fact[MX - 1]);
    for (int i = MX - 1; i >= 1; i--) {
        ifact[i - 1] = ifact[i] * i % MOD;
    }

    auto comb = [&](int n, int r) -> ll {
        if (r < 0 || r > n) return 0;
        return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
    };

    auto perm = [&](int n, int r) -> ll {
        if (r < 0 || r > n) return 0;
        return fact[n] * ifact[n - r] % MOD;
    };
    // <---------------- comb, perm の前計算 [ End ] ----------------<

}

// tetrahedral number : Σ[k = 1..N] Σ[i = 1..k] i
ll tetra(ll N) {
    // N * (N+1) * (N+2) / 6
    return N * (N + 1) % MOD * (N + 2) % MOD * mod_inv(6) % MOD;
}

// >---------------- mod [Begin] ---------------->
// 任意 MOD 数列和

using i128 = __int128;

// a ^ e mod M
ll mpow(ll a, ll e, ll m) {
    i128 r = 1, x = a % m;
    while (e) {
        if (e & 1) r = r * x % m;
        x = x * x % m;
        e >>= 1;
    }
    return (ll)r;
}

// \sum i=[0..T-1] r^i (mod M)
ll sum_geom(ll r, ll T, ll M) {
    if (r == 1) return T % M;
    ll mod = M * (r - 1);
    i128 x = mpow(r, T, mod) - 1;
    x /= (r - 1);
    return (ll)(x % M);
}

// \sum i=[0..T-1] i r^i (mod M)
ll sum_w_geom(ll r, ll T, ll M) {
    if (r == 1) {
        i128 x = (i128)T * (T - 1) / 2;
        return (ll)(x % M);
    }
    ll Mr = M * (r - 1);
    i128 x = (i128)(T - 1) * mpow(r, T, Mr);
    x -= sum_geom(r, T, Mr);
    x += 1;
    x /= (r - 1);
    return (ll)x;
}

// <---------------- mod [ End ] ----------------<
