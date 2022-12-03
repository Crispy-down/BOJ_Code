#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A,B,C;

ll mod_func(ll a,ll b,ll m) {
    if(b==1) return a % m; // base condition (a가 m보다 클수도 있어서 a % m)
    ll val = mod_func(a, b/2, m); // 재귀적으로 a b/2 mod m 계산.
    val = val * val % m; // val 제곱.
    if(b%2 == 0) return val; // b가 짝수일 때
    return val * a % m; // b가 홀수일 때
}
// b를 절반으로 나누고, 제곱한 연산 결과를 저장.
// 계속 나누다보면 base condition 수렴.
// 결과적으로, 1승의 값을 가지고 2k승의 값들을 구할 수 있음.
// b가 절반씩 깎여서 O(log b)


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

// A,B,C가 모두 21억 이하의 자연수,
// 위와 같이 거듭제곱을 계산해버리면,
// (반복문)
// overflow는 해결이 가능함.(곱셈 연산 후 mod 연산을 해버림)
// ex) (a x b x c) mod N = a mod N x b mod N x c mod N
// 위의 함수로는 O(b)에 구할 수 있다.
// 그러나 이 문제로는 b가 최대 20억이라, O(b)로는 해결이 불가능하다.
// 따라서, 효율적인 방법을 이용해야하는데,
// ex) 12 ^ 116 mod 67을 구하고자함
// => 12^58 mod 67 = 4인걸 암
// a mod b = c , a^2 mod b = c^2
// (a mod b x a mod b = a^2 mod b)
// 12^58 mod 67 x 12^58 mod 67 = 16
// = 12^116 mod 67 = 16
// 12^117 mod 67 = 12^116 mod 67 x 12 mod 67

// 예시로 들면,
// 1번 도미노가 쓰러진다.
// k번 도미노가 쓰러지면 k + 1 번 도미노도 쓰러진다.
// ==
// 1승을 계산할 수 있다.
// k승을 계산하면 k + 1승을 계산할 수 있다.
// ==
// 1승을 계산할 수 있다.
// k승을 계산했으면, 2k승과 2k+1승도 O(1)에 계산할 수 있다.
// 위 12 .. ex와 같이.
// 와 같이 귀납법으로 해결을 할 수 있다.
//