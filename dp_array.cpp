#include "template.h"

// >---------------- DP Array [Begin] ---------------->

template<class T>
struct DP2D {
    int h, w;
    T out;
    vector<vector<T>> v;

    // 範囲外の返り値を out に設定
    DP2D(int h, int w, T out) : h(h), w(w), out(out), v(h, vector<T>(w)) {}

    // 読み取り用（範囲外は out を返す）
    T operator()(int i, int j) const {
        if (i < 0 || i >= h || j < 0 || j >= w) return out;
        return v[i][j];
    }

    // 書き込み用（範囲内前提）
    T& at(int i, int j) {
        return v[i][j];
    }
};

// <---------------- DP Array [ End ] ----------------<


// >---------------- DP Array 1D [Begin] ---------------->

template<class T>
struct DP1D {
    int n;
    T out;
    vector<T> v;

    // 範囲外の返り値を out に設定
    DP1D(int n, T out) : n(n), out(out), v(n) {}

    // 読み取り用（範囲外は out を返す）
    T operator[](int i) const {
        if (i < 0 || i >= n) return out;
        return v[i];
    }

    // 書き込み用（範囲内前提）
    T& at(int i) {
        return v[i];
    }
};

// <---------------- DP Array 1D [ End ] ----------------<
