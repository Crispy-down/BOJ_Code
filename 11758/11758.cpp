#include <bits/stdc++.h>
#define x first 
#define y second

using namespace std;
using ll = long long;
using point = pair<ll, ll>;
using vec = pair<ll, ll>;

ll p1_x,p1_y,p2_x,p2_y,p3_x,p3_y;

vec get_vector(vec& a, vec& b) { // ���� a b�� ������ �Լ�
    return {b.x-a.x , b.y - a.y};
}

int ccw(vec& u, vec& v) {  // ���� u v�� ������ �����ϴ� ccw �Լ�
    ll cross_product = u.x * v.y - u.y * v.x;
    if(cross_product > 0) return 1; // �ݽð� ����
    else if(cross_product < 0) return -1; // �ð� ����
    else return 0; // ����
}

int ccw(point& a, point& b, point& c) {  // �� �� a,b,c�� ���ʴ�� �̾��� �� ������ �����ϴ� ccw �Լ�
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
// 2���� ���� u, v�� ���� ��, u�� v�� � ������ �̷�� �ִ��� �����ϴ� ���

// u, v �� �ݽð� �������� �����ִ��� ����
// �� ������ ������ ���.
// | u x v | = |u||v| sin theta
// sin���� ��ȣ�� �̿��� ���� ��������

// �� ���Ͱ� �ݽð� ���� -> sin �� ���
// �� ���Ͱ� �ð� ���� -> sin �� ����