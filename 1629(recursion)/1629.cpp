#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A,B,C;

ll mod_func(ll a,ll b,ll m) {
    if(b==1) return a % m; // base condition (a�� m���� Ŭ���� �־ a % m)
    ll val = mod_func(a, b/2, m); // ��������� a b/2 mod m ���.
    val = val * val % m; // val ����.
    if(b%2 == 0) return val; // b�� ¦���� ��
    return val * a % m; // b�� Ȧ���� ��
}
// b�� �������� ������, ������ ���� ����� ����.
// ��� �����ٺ��� base condition ����.
// ���������, 1���� ���� ������ 2k���� ������ ���� �� ����.
// b�� ���ݾ� �𿩼� O(log b)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;

    cout << mod_func(A,B,C);

    return 0;
}

// ll func1(ll a, ll b , ll c) {
//     ll var = 1;
//     while(b--) {
//         var = var * a % c;
//     }
//     return var;
// }

// A,B,C�� ��� 21�� ������ �ڿ���,
// ���� ���� �ŵ������� ����ع�����,
// (�ݺ���)
// overflow�� �ذ��� ������.(���� ���� �� mod ������ �ع���)
// ex) (a x b x c) mod N = a mod N x b mod N x c mod N
// ���� �Լ��δ� O(b)�� ���� �� �ִ�.
// �׷��� �� �����δ� b�� �ִ� 20���̶�, O(b)�δ� �ذ��� �Ұ����ϴ�.
// ����, ȿ������ ����� �̿��ؾ��ϴµ�,
// ex) 12 ^ 116 mod 67�� ���ϰ�����
// => 12^58 mod 67 = 4�ΰ� ��
// a mod b = c , a^2 mod b = c^2
// (a mod b x a mod b = a^2 mod b)
// 12^58 mod 67 x 12^58 mod 67 = 16
// = 12^116 mod 67 = 16
// 12^117 mod 67 = 12^116 mod 67 x 12 mod 67

// ���÷� ���,
// 1�� ���̳밡 ��������.
// k�� ���̳밡 �������� k + 1 �� ���̳뵵 ��������.
// ==
// 1���� ����� �� �ִ�.
// k���� ����ϸ� k + 1���� ����� �� �ִ�.
// ==
// 1���� ����� �� �ִ�.
// k���� ���������, 2k�°� 2k+1�µ� O(1)�� ����� �� �ִ�.
// �� 12 .. ex�� ����.
// �� ���� �ͳ������� �ذ��� �� �� �ִ�.
//