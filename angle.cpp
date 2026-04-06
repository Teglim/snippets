#include "template.h"

// >---------------- Angle [Begin] ---------------->

ld angle_rad(pll X, pll Y, pll Z) {
    ld ax = X.first  - Y.first;
    ld ay = X.second - Y.second;
    ld bx = Z.first  - Y.first;
    ld by = Z.second - Y.second;

    ld dot = ax * bx + ay * by;

    ld na = sqrtl(ax * ax + ay * ay);
    ld nb = sqrtl(bx * bx + by * by);

    if (na == 0 || nb == 0) return 0.0L;

    ld c = dot / (na * nb);

    // clamp
    c = max((ld)-1.0, min((ld)1.0, c));

    return acosl(c);
}

ld angle_deg(pll X, pll Y, pll Z) {
    const ld PI = acosl(-1.0L);
    return angle_rad(X, Y, Z) * 180.0L / PI;
}

// <---------------- Angle [ End ] ----------------<


// >---------------- Vector Angle [Begin] ---------------->

const ld PI = acosl(-1.0L);

// 偏角（弧度法）: x軸から反時計回り [0, 2π)
ld arg_rad(pll V) {
    ld a = atan2l(V.second, V.first); // [-π, π]

    if (a < 0) a += 2.0L * acosl(-1.0L);
    return a;
}

// 偏角（度数法）: x軸から反時計回り [0, 360)
ld arg_deg(pll V) {
    return arg_rad(V) * 180.0L / PI;
}

// 2点版（Y→X ベクトルの角度）
ld arg_rad(pll from, pll to) {
    return arg_rad({to.first - from.first, to.second - from.second});
}

ld arg_deg(pll from, pll to) {
    return arg_rad(from, to) * 180.0L / PI;
}

// sort(all(ps), [](pll a, pll b){
//     return arg_rad(a) < arg_rad(b);
// });

// <---------------- Vector Angle [ End ] ----------------<
