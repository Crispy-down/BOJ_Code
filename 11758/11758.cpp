#include <bits/stdc++.h>
#define x first 
#define y second

using namespace std;
using ll = long long;
using point = pair<ll, ll>;
using vec = pair<ll, ll>;

ll p1_x,p1_y,p2_x,p2_y,p3_x,p3_y;

vec get_vector(vec& a, vec& b) { // 벡터 a b를 얻어오는 함수
    return {b.x-a.x , b.y - a.y};
}

int ccw(vec& u, vec& v) {  // 벡터 u v의 방향을 판정하는 ccw 함수
    ll cross_product = u.x * v.y - u.y * v.x;
    if(cross_product > 0) return 1; // 반시계 방향
    else if(cross_product < 0) return -1; // 시계 방향
    else return 0; // 평행
}

int ccw(point& a, point& b, point& c) {  // 각 점 a,b,c를 차례대로 이었을 때 방향을 판정하는 ccw 함수
    vec u = get_vector(a,b);
    vec v = get_vector(b,c);
    return ccw(u,v);
}

int main() {
    cin >> p1_x >> p1_y >> p2_x >> p2_y >> p3_x >> p3_y;
    point p1 = {p1_x,p1_y};
    point p2 = {p2_x,p2_y};
    point p3 = {p3_x,p3_y};
    cout << ccw(p1,p2,p3);
}
// CCW (Counter - Clockwise)
// 2차원 벡터 u, v가 있을 때, u와 v가 어떤 방향을 이루고 있는지 판정하는 방법

// u, v 가 반시계 방향으로 놓여있는지 판정
// 두 벡터의 외적값 사용.
// | u x v | = |u||v| sin theta
// sin값의 부호를 이용해 방향 판정가능

// 두 벡터가 반시계 방향 -> sin 값 양수
// 두 벡터가 시계 방향 -> sin 값 음수