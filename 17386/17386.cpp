#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using ll = long long;
using vec = pair<ll,ll>;
using point = pair<ll,ll>;

ll l1_sx,l1_sy,l1_ex,l1_ey;
ll l2_sx,l2_sy,l2_ex,l2_ey;

vec make_vec(vec& a, vec& b) {
    return {b.x - a.x , b.y - a.y};
}

int ccw(vec& a, vec& b) {
    ll cross_product = a.x * b.y - a.y * b.x;
    if(cross_product < 0) { // overflow 방지를 위해 리턴값을 int로
        return -1;
    }
    else if(cross_product > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int ccw(point& a, point& b , point& c) {
    vec u = make_vec(a,b);
    vec v = make_vec(b,c);
    return ccw(u,v);
}



int main() {
    cin >> l1_sx >> l1_sy >> l1_ex >> l1_ey;
    cin >> l2_sx >> l2_sy >> l2_ex >> l2_ey;

    point L1_start = {l1_sx,l1_sy};
    point L1_end = {l1_ex,l1_ey};
    point L2_start = {l2_sx,l2_sy};
    point L2_end = {l2_ex,l2_ey};


    if(ccw(L1_start,L1_end,L2_start) * ccw(L1_start,L1_end,L2_end) < 0 &&
    ccw(L2_start,L2_end,L1_start) * ccw(L2_start,L2_end,L1_end) < 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    
}

