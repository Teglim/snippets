#include "template.h"

// >---------------- prime [Begin] ---------------->

// 約数列挙（昇順）
template <typename T>
vector<T> enum_div(T n) { 
    vector<T> S;
    for (T i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            S.push_back(i);
            if (i*i != n) S.push_back(n / i);
        }
    }
    sort(S.begin(), S.end());
    return S;
}

// 素因数分解
template <typename T>
vector<pair<T, T>> prime_factorize(T n) {
    vector<pair<T, T>> ret;
    for (T i = 2; i*i <= n; i++) {
        if (n % i != 0) continue;
        T num = 0;
        while (n % i == 0) { num++; n /= i; }
        ret.emplace_back(i, num);
    }
    if (n != 1) ret.emplace_back(n, 1);
    return ret;
}

// 素因判定
template <typename T>
bool is_prime(T num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    for (T i = 3; i*i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// 素数判定列（Sieve of Eratosthenes）
vector<bool> is_primes(int n) {
    vector<bool> v(n + 1, true);
    v[0] = false, v[1] = false;
    for (int i = 2; i*i <= n; ++i) {
        if (!v[i]) continue;
        for (ll j = i*i; j <= n; j += i) v[j] = false;
    }
    return v;
}

// <---------------- prime [End] ----------------<
