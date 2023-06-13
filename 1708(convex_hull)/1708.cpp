#include <bits/stdc++.h>
#define x first 
#define y second

using namespace std;
using ll = long long;
using vec = pair<ll,ll>;
using point = pair<ll,ll>;

vector <point> pts;

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
    else return 0;
}

int ccw(point& a, point& b, point& c) {
    vec u = make_vec(a,b);
    vec v = make_vec(b,c);
    return ccw(u,v);
}

vector<point> get_part_of_hull(vector<point>& p) {
    int n = p.size();
    vector<point> hull;
    for(int i = 0;i<n;i++) {
        while(hull.size() >= 2) {
            int m = hull.size();
            if(ccw(hull[m-2], hull[m-1], p[i]) > 0) break;
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }
    return hull;
}

vector<point> get_convex_hull(vector<point> & p) {
    sort(p.begin(), p.end());
    vector<point> up = get_part_of_hull(p);

    reverse(p.begin(), p.end());
    vector<point> down = get_part_of_hull(p);

    up.insert(up.end(), down.begin() + 1, down.end() -1);
    return up;
}

int main() {
    int N;
    cin >> N;
    ll a,b;
    for(int i = 0;i<N;i++) {
        cin >> a >> b;
        point p = {a,b};
        pts.push_back(p);
    }

    cout << get_convex_hull(pts).size();


}

