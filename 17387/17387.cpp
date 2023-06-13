#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using ll = long long;
using vec = pair<ll,ll>;
using point = pair<ll,ll>;

vec make_vec(vec& a, vec& b) {
    return {b.x - a.x , b.y - a.y};
}

int ccw(vec& u, vec& v) {
    ll cross_product = u.x * v.y - u.y * v.x;
    if(cross_product > 0) {
        return 1;
    }
    else if(cross_product < 0) {
        return -1;
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
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    point px1 = {x1,y1};
    point px2 = {x2,y2};
    point px3 = {x3,y3};
    point px4 = {x4,y4};

    int ans1 = ccw(px1,px2,px3) * ccw(px1,px2,px4);
    int ans2 = ccw(px3,px4,px1) * ccw(px3,px4,px2);

    if(ans1 == 0 && ans2 == 0) { // 한 직선에 다 있는 경우
        if(px1 > px2) swap(px1,px2);
        if(px3 > px4) swap(px3,px4);
        if(px1 <= px4 && px2 >= px3) { // A <= D , B >= C
            cout << 1;
        }
        else cout << 0;
    }     
    else {
        if(ans1 <= 0 && ans2 <= 0) { // 둘 중 하나가 0 or 둘 다 음수
            cout << 1;
        }
        else {
            cout << 0;
        }

    }

}