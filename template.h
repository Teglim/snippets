#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using mint = modint998244353;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

template <typename T> using v = vector<T>;
template <typename T> using vv = vector<vector<T>>;

using ll = long long;       using ld = long double;
using vi = v<int>;          using vll = v<ll>;          using vld = v<ld>;        using vs = v<string>;
using vvi = vv<int>;        using vvll = vv<ll>;        using vvld = vv<ld>;
using pii = pair<int, int>; using pll = pair<ll, ll>;   using pld = pair<ld, ld>;
using vpii = v<pii>;        using vpll = v<pll>;        using vpld = v<pld>;
using vvpii = vv<pii>;      using vvpll = vv<pll>;      using vvpld = vv<pld>;
using mll = map<ll, ll>;    using umll = unordered_map<ll, ll>;
using pq_gr = priority_queue<ll, vi, greater<ll>>;

#endif /* TEMPLATE_H */
