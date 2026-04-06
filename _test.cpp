#include "template.h"

// 区間マージ
struct IntervalUnion {
    vpll seg;
    bool built = false;

    // 閉区間 [L, R]
    void add(ll L, ll R) {
        if (L > R) return;
        seg.emplace_back(L, R);
        built = false;
    }

    void build() {
        if (built) return;
        if (seg.empty()) {
            built = true;
            return;
        }

        sort(all(seg));

        vpll merged;
        ll L = seg[0].first;
        ll R = seg[0].second;

        for (int i = 1; i < (int)seg.size(); i++) {
            // もし 連続区間 [1,3] と [4,5] をマージしたくないなら
            // if (seg[i].first <= R)
            // に変えること。
            if (seg[i].first <= R + 1) {
                R = max(R, seg[i].second);
            } else {
                merged.emplace_back(L, R);
                L = seg[i].first;
                R = seg[i].second;
            }
        }
        merged.emplace_back(L, R);

        seg.swap(merged);
        built = true;
    }

    // 和集合の長さ取得
    ll length() {
        build();
        ll res = 0;
        for (int i = 0; i < (int)seg.size(); i++) {
            res += seg[i].second - seg[i].first + 1;
        }
        return res;
    }

    const vpll& get() {
        build();
        return seg;
    }
};

int main() {
    IntervalUnion iu;
    iu.add(1, 3);
    iu.add(2, 4);
    iu.add(5, 6);
    iu.add(7, 8);

    iu.build();

    auto v = iu.get();
    for (auto [l, r] : v) {
        cout << l << " " << r << '\n';
    }
    cout << iu.length() << '\n';
}
