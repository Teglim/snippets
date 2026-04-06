#include "template.h"

// >---------------- Lazy Segtree [Begin] ---------------->
// 区間加算・区間最小値取得

using S = ll;
using F = ll;

const S INF = (1LL << 60);

S op(S a, S b) { return min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

// sample constructor
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int N);

// <---------------- Lazy Segtree [ End ] ----------------<


// >---------------- Lazy Segtree [Begin] ---------------->
// 区間加算・区間最大値取得

using S = ll;
using F = ll;

const S NINF = -(1LL << 60);

S op(S a, S b) { return max(a, b); }
S e() { return NINF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

// sample constructor
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int N);

// <---------------- Lazy Segtree [ End ] ----------------<


// >---------------- Lazy Segtree [Begin] ---------------->
// 区間加算・区間和取得

struct S{
    ll val;
    int size;
};
using F = ll;

S op(S a, S b) { return {a.val + b.val, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {x.val + f * x.size, x.size}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

// sample constructor
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int N);

// <---------------- Lazy Segtree [ End ] ----------------<


// >---------------- Lazy Segtree [Begin] ---------------->

// モノイドの型
using T = int;

// 写像の型
using F = int;

// 写像
T op(T l, T r) { return l + r; }

// 単位元
T e() { return T{0}; }

// f(x) を返す
T mapping(F f, T x) { return f == -1 ? x : f * x; }

// f ∘ g を返す
F composition(F f, F g) { return f == -1 ? g : f; }

// 恒等写像 id を返す
F id() { return F{-1}; }

// sample constructor
// lazy_segtree<T, op, e, F, mapping, composition, id> seg(int n);
// lazy_segtree<T, op, e, F, mapping, composition, id> seg(vector<T> v);

// <---------------- Lazy Segtree [ End ] ----------------<

// >---------------- Lazy Segtree [Begin] ---------------->

// // モノイドの型
// struct S {
//     mint a;
//     int size;
// };

// // 写像の型
// struct F {
//     mint a, b;
// };

// // 写像
// S op(S l, S r) { return S{l.a + r.a, l.size + r.size}; }

// // 単位元
// S e() { return S{0, 0}; }

// // f(x) を返す
// S mapping(F f, S x) { return S{x.a * f.a + x.size * f.b, x.size}; }

// // f ∘ g を返す
// F composition(F f, F g) { return F{g.a * f.a, g.b * f.a + f.b}; }

// // 恒等写像 id を返す
// F id() { return F{1, 0}; }

// // sample constructor
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);

// <---------------- Lazy Segtree [ End ] ----------------<
