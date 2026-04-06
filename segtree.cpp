#include "template.h"

// >---------------- Segtree [Begin] ---------------->

// モノイドの型
struct T {
    int cnt;
    ll sum; // cnt * num
};

// 写像
T op(T a, T b) {
    return T{a.cnt + b.cnt, a.sum + b.sum};
}

// 単位元
T e() {
    return T{0, 0};
}

// sample constructor
// segtree<T, op, e> seg(int n);
// segtree<T, op, e> seg(vector<S> v);

// <---------------- Segtree [ End ] ----------------<
