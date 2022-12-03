#include <bits/stdc++.h>
using namespace std;

int N,R,C;

int func(int n,int r,int c) {
    if(n == 0) {
        return 0;
    }
    int half = 1 << (n-1); // 이전 단계의 한변의 길이
    if(r < half && c < half) return func(n-1,r,c);
    if(r < half && c >= half) return half*half + func(n-1,r,c-half);
    if(r >= half && c < half) return 2*half*half + func(n-1,r-half,c);
    return 3*half*half + func(n-1,r-half,c-half);
    // 이전단계로 귀납적으로 들어가는 재귀식
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> R >> C;
    cout << func(N,R,C);


    return 0;
}