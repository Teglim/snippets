#include "template.h"

// >---------------- 転倒数 [Begin] ---------------->
/* Fenwick tree は ACL に依存します */

// 転倒数 (l < i かつ a[l] > a[i] を満たすペア数)
ll inversion_number(const vector<int>& a) {
    int n = a.size();

    // 座標圧縮
    vector<int> xs = a;
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());

    fenwick_tree<ll> bit(xs.size());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int id = lower_bound(all(xs), a[i]) - xs.begin();
        ans += i - bit.sum(0, id + 1);
        bit.add(id, 1);
    }

    return ans;
}

// <---------------- 転倒数 [ End ] ----------------<


// >---------------- 増加ペア数 [Begin] ---------------->
/* Fenwick tree は ACL に依存します */

// l < i かつ a[l] < a[i] を満たすペア数
ll increasing_pairs(const vector<int>& a) {
    int n = a.size();

    // 座標圧縮
    vector<int> xs = a;
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());

    fenwick_tree<ll> bit(xs.size());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int id = lower_bound(all(xs), a[i]) - xs.begin();
        ans += bit.sum(0, id);
        bit.add(id, 1);
    }

    return ans;
}

// <---------------- 増加ペア数 [ End ] ----------------<
