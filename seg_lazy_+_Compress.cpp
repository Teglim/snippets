#include "template.h"

// >---------------- Lazy Segtree + Compression [Begin] ---------------->
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

// 座標圧縮
struct Compression {
    vll xs;  // xs[id] -> val

    Compression(const vll& a) {
        xs = a;
        sort(all(xs));
        xs.erase(unique(all(xs)), xs.end());
    }

    // id -> val
    int val(int id) const { return xs[id]; }

    // val -> id
    int id(int val) const {
        return lower_bound(all(xs), val) - xs.begin();
    }

    int size() const { return (int)xs.size(); }
};

struct SegWrapper {
    Compression comp;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg;

    SegWrapper(const vll& xs)
        : comp(xs), seg(comp.size()) {}

    int id_of(ll x) {
        return lower_bound(all(comp.xs), x) - comp.xs.begin();
    }

    int id_r(ll x) {
        return upper_bound(all(comp.xs), x) - comp.xs.begin();
    }

    // 区間加算 (val閉区間)
    void add_val(ll l, ll r, ll x) {
        int L = id_of(l);
        int R = id_r(r);
        if (L < R) seg.apply(L, R, x);
    }

    // 区間加算 (id閉区間)
    void add_id(int l, int r, ll x) {
        seg.apply(l, r + 1, x);
    }

    // 区間prod (val閉区間)
    ll prod_val(ll l, ll r) {
        int L = id_of(l);
        int R = id_r(r);
        if (L >= R) return INF;
        return seg.prod(L, R);
    }

    // 区間prod (id閉区間)
    ll prod_id(int l, int r) {
        return seg.prod(l, r + 1);
    }

    // 一点更新 (id)
    void set_id(int i, ll x) {
        seg.set(i, x);
    }

    // 一点更新 (val)
    void set_val(ll x, ll v) {
        seg.set(comp.id(x), v);
    }

    // 一点取得 (id)
    ll get_id(int i) {
        return seg.get(i);
    }

    // 一点取得 (val)
    ll get_val(ll x) {
        return seg.get(comp.id(x));
    }

    int size() {
        return comp.size();
    }

    ll val(int i) {
        return comp.val(i);
    }
};

// <---------------- Lazy Segtree + Compression [ End ] ----------------<
