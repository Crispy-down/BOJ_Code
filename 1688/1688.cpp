#include <bits/stdc++.h>
#define x first 
#define y second 

using namespace std;
using ll = long long;
using vec = pair{ll,ll};
using point = pair{ll,ll};

vector <point> pts;
int N;
ll a,b;

vec make_vec(vec& a, vec& b) {
    return {b.x - a.x , b.y - a.y};
}

int ccw(vec& u, vec& v) {
    ll cross_product = u.x * v.y - u.y * v.x;
    if(cross_product > 0) {
        return 1;
    }
    else if(cross_product < 0){
        return -1;
    }
    else return 0;
}

int ccw(point& a, point& b, point& c) {
    vec u = make_vec(a,b);
    vec v = make_vec(b,c);
}

int main() {
    cin >> N;
    for(int i = 0;i<N;i++) {
        cin >> a >> b;
        point p = {a,b};
        pts.push_back(p);
    }
    int proper_way = -2;
    for(int i = 0;i<N-2;i++) {
        int way = ccw(pts[i],pts[i+1],pts[i+2]);
        if(way != 0) {
            proper_way = way;
        }
    }
    if(proper_way == -2) {
        proper_way = 0;
    }
    for(int i = 0;i<3;i++) {
        cin >> a >> b;
        point p2 = {a,b};
        if(ccw(pts[0],pts[1],p2) != proper_way) {
            cout << 0 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
    }

}