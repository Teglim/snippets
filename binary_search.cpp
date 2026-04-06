#include "template.h"

// >---------------- binary search [Begin] ---------------->
// 最小化

// lim が真の答え "以上" か？つまり、lim は満たす範囲であるか
auto check = [&](ll lim) -> bool {
    /* Add Here */
};

// 答えの上界．INT64_MAX では OF する危険アリ
const ll SUP = (1L << 60);

// 二分探索
auto bs = [&]() -> ll {
    ll ng = -1, ok = SUP;
    while (ng + 1 < ok) {
        ll md = (ng + ok) / 2;
        if (check(md)) ok = md;
        else ng = md;
    }
    return ok;
};

// cout << bs() << '\n';

// <---------------- binary search [ End ] ----------------<


// >---------------- binary search [Begin] ---------------->
// 最大化

// lim が真の答え "以下" か？つまり、lim は満たす範囲であるか
auto check = [&](ll lim) -> bool {
    /* Add Here */
};

// 答えの上界（含まないことに注意）．INT64_MAX では OF する危険アリ
const ll SUP = (1L << 60);

// 二分探索
auto bs = [&]() -> ll {
    ll ok = -1, ng = SUP;
    while (ok + 1 < ng) {
        ll md = (ok + ng) / 2;
        if (check(md)) ok = md;
        else ng = md;
    }
    return ok;
};

// cout << bs() << '\n';

// <---------------- binary search [ End ] ----------------<
