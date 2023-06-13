#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using ll = long long;
using vec = pair<ll,ll>;
using point = pair<ll,ll>;

int T;
vector <point> pts;
ll a,b;
double ans = 0;

vec make_vec(vec& a, vec& b) {
    return {b.x - a.x , b.y - a.y};
}

double area(vec& a, vec& b) {
    ll cross_product = a.x * b.y - a.y * b.x;
    double product_area = cross_product / 2.0; // 오목 다각형때문에 그냥 ccw 값 자체를 더해야함
    return product_area;
}

double ccw(point& a, point& b, point& c) {
    vec u = make_vec(a,b);
    vec v = make_vec(b,c);
    return area(u,v); 
}

int main() {
    cin >> T;
    while(T--) {
        cin >> a >> b;
        point p = {a,b};
        pts.push_back(p);
    }

    for(int i = 1;i<pts.size()-1;i++) {
        ans += ccw(pts[0],pts[i],pts[i+1]);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(ans);
    
}
