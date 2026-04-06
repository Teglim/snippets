#include "template.h"

// >---------------- Segtree [Begin] ---------------->
// min

ll min_op(ll a, ll b) { return min(a, b); }
ll min_e() { return INT64_MAX; }

// segtree<ll, min_op, min_e> min_seg(N);

// <---------------- Segtree [ End ] ----------------<

// >---------------- Segtree [Begin] ---------------->
// Max

ll max_op(ll a, ll b) { return max(a, b); }
ll max_e() { return INT64_MIN; }

// segtree<ll, max_op, max_e> max_seg(N);

// <---------------- Segtree [ End ] ----------------<

// >---------------- Segtree [Begin] ---------------->
// Sum

ll op(ll a, ll b) { return a + b; }
ll e() { return 0LL; }

// segtree<ll, op, e> seg(N);

// <---------------- Segtree [ End ] ----------------<

// >---------------- Segtree [Begin] ---------------->
// GCD

ll op(ll a, ll b) { return gcd(a, b); }
ll e() { return 0LL; }

// segtree<ll, op, e> seg(N);

// <---------------- Segtree [ End ] ----------------<
