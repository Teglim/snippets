#include "template.h"

// >---------------- Fenwick tree [Begin] ---------------->
/* 実装は ACL にあります */

// init
// fenwick_tree<T> fw(int n);

// a[p] += x
// void fw.add(int p, T x)

// a[l] + a[l + 1] + ... + a[r - 1]
// T fw.sum(int l, int r)

// <---------------- Fenwick tree [ End ] ----------------<


// >---------------- Fenwick tree [Begin] ---------------->
// kth が欲しいBIT
struct BIT {
    int n;
    vi t;
    int pc = 0;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void add(int i, int v) {
        pc += v;
        for (; i <= n; i += i & -i) t[i] += v;
    }
    int kth(ll k) {
        int x = 0;
        for (int i = 1 << 19; i > 0; i >>= 1) {
            if (x + i <= n && t[x + i] < k) {
                x += i;
                k -= t[x];
            }
        }
        return x + 1;
    }
};
// <---------------- Fenwick tree [ End ] ----------------<


// >---------------- Fenwick tree [Begin] ---------------->
// XOR BIT
struct BIT {
    int n;
    vi t;

    BIT(int n) : n(n), t(n + 1) {}

    void add(int i, int x) {
        for (i++; i <= n; i += i & -i) t[i] ^= x;
    }

    int sum(int r) {
        int s = 0;
        for (; r > 0; r -= r & -r) s ^= t[r];
        return s;
    }

    int sum(int l, int r) {
        return sum(r) ^ sum(l);
    }
};
// <---------------- Fenwick tree [ End ] ----------------<


// >---------------- Fenwick tree [Begin] ---------------->

// template <class Abel> struct BIT {
//     Abel UNITY_SUM = 0;
//     vector<Abel> dat;
    
//     // [0, n)
//     BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n, unity) { }
//     void init(int n) {
//         dat.assign(n, UNITY_SUM);
//     }
    
//     // a is 0-indexed
//     inline void add(int a, Abel x) {
//         for (int i = a; i < (int)dat.size(); i |= i + 1)
//             dat[i] = dat[i] + x;
//     }
    
//     // [0, a), a is 0-indexed
//     inline Abel sum(int a) {
//         Abel res = UNITY_SUM;
//         for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)
//             res = res + dat[i];
//         return res;
//     }
    
//     // [a, b), a and b are 0-indexed
//     inline Abel sum(int a, int b) {
//         return sum(b) - sum(a);
//     }
    
//     // debug
//     void print() {
//         for (int i = 0; i < (int)dat.size(); ++i)
//             cout << sum(i, i + 1) << ",";
//         cout << endl;
//     }
// };

// <---------------- Fenwick tree [ End ] ----------------<
