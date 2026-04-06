#include "template.h"

// >---------------- Util ---------------->

// all_combination : 1 <= cand[i] <= M を満たす N 項広義単調増加列の全列挙
auto all_comb = [&](int N, int M) {
    ll ans = 0;

    vi cand(N, 1);
    while (true) {
        /* add here */

        int i = N - 1;
        while (i >= 0 && cand[i] == M) i--;
        if (i < 0) break;

        cand[i]++;

        for (int j = i + 1; j < N; j++) cand[j] = cand[i];
    }

    cout << ans << '\n';
};

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
            // もし 連続区間 [1,3] と [4,5] などをマージしたくないなら
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

// 10進数での桁数
ll digit_10(ll N) {
    if (N == 0) return 1;
    if (N < 0) N = -N;
    ll cnt = 0;
    while (N > 0) {
        N /= 10;
        cnt++;
    }
    return cnt;
}

// 座標の点
class Point {
public:
    int x, y;

    Point() : x(0), y(0) {}
    Point(int x_, int y_) : x(x_), y(y_) {}
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    ld distance_to(const Point& other) const {
        ld dx = x - other.x;
        ld dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};


struct Node {
    int x, y;

    bool operator<(const Node& o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};


// priority_queue usage
struct Data {
    int value;
    vi buy;

    // < : Max Heap、 > : Min Heap
    // Default is "< : Max Heap"
    bool operator<(const Data& other) const {
        return value < other.value;
    }
};
// priority_queue<Data> pq;


// vec 出力補助関数
void print_vec(const vi& ans) {
    int size = ans.size();
    for (int i = 0; i < size; i++) cout << (i ? " " : "") << ans[i];
    cout << '\n';
}

// vec 逆順出力補助関数
void print_vec_reverse(const vi& ans) {
    int size = ans.size();
    for (int i = 0; i < size; i++) cout << (i ? " " : "") << ans[size - 1 - i];
    cout << '\n';
}

// ランレングス圧縮
vector<pair<char, int>> RLE(const string& S) {
    vector<pair<char, int>> rl;
    if (S.empty()) return rl;

    char cur = S[0];
    int cnt = 1;

    for (int i = 1; i < S.size(); i++) {
        if (S[i] == cur) {
            cnt++;
        } else {
            rl.emplace_back(cur, cnt);
            cur = S[i];
            cnt = 1;
        }
    }
    rl.emplace_back(cur, cnt);
    return rl;
}


// 座標圧縮
struct Compression {
    vector<int> xs;  // xs[id] -> val

    Compression(const vector<int>& a) {
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


// sum[i = S..T] min(max(R−i, 0), R−L+1)
ll clipped_sum(ll L, ll R, ll S, ll T) {
    if (S > T) return 0;

    ll ans = 0;

    // --- 1. 定数区間 i <= L-1 ---
    ll left_end = min(T, L - 1);
    if (S <= left_end) {
        ll n1 = left_end - S + 1;
        ans += n1 * (R - L + 1);
    }

    // --- 2. 直線区間 L <= i <= R ---
    ll a = max(S, L);
    ll b = min(T, R);
    if (a <= b) {
        ll n2 = b - a + 1;
        ans += n2 * R - (a + b) * n2 / 2;
    }

    // --- 3. i >= R+1 は 0 なので何もしない ---

    return ans;
}

// 床除算
ll floordiv(ll a, ll b) {
    ll q = a / b;
    ll r = a % b;
    if (r != 0 && ((r > 0) != (b > 0))) q--;
    return q;
}

// 天井除算
ll ceildiv(ll a, ll b) {
    ll q = a / b;
    ll r = a % b;
    if (r != 0 && ((r > 0) == (b > 0))) q++;
    return q;
}

int main() {
    int N;

    vll v;
    sort(all(v), [](const auto& a, const auto& b) -> bool {
        return a < b;
    });
    
    // bit 全探索
    for (int bit = 0; bit < (1 << N); bit++) {
        for (int i = 0; i < N; i++) {
            if (bit >> i & 1) {
                /* i 番目の bit が立っているとき */

            } else {

            }
        }
    }

    // bit 全探索 辞書順
    for (int bit = 0; bit < (1 << N); bit++) {
        for (int i = 0; i < N; i++) {
            if (bit >> (N - 1 - i) & 1) {
                /* i 番目の bit が立っているとき */
                
            } else {

            }
        }
    }


    // 順列全探索
    vi v(N);
    iota(all(v), 0);
    do {
        /* v を次々に順列として */
    } while(next_permutation(all(v)));


    // 中央値管理
    int Q; cin >> Q;

    priority_queue<int> lq;
    priority_queue<int, vector<int>, greater<int>> rq;

    while (Q--) {
        int q; cin >> q;
        if (q == 1) {
            int a, b;
            cin >> a >> b;
            if (lq.empty() || a <= lq.top()) {
                lq.push(a);
            } else {
                rq.push(a);
            }
            if (lq.size() > rq.size() + 1) {
                int ltop = lq.top();
                lq.pop();
                rq.push(ltop);
            } else if (rq.size() > lq.size()) {
                int rtop = rq.top();
                rq.pop();
                lq.push(rtop);
            }
        }
        if (q == 2) {
            ll median = lq.top();
            cout << median << '\n';
        }
    }
}

// <---------------- Util ----------------<
