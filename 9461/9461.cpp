#include <iostream>

using namespace std;

unsigned long long dp[102] = {0};

int main() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i =4;i<101;i++) {
        dp[i] = dp[i-2] + dp[i-3];
    }
    int n,tmp;
    cin >> n;
    for(int i =0;i<n;i++) {
        cin >> tmp;
        cout << dp[tmp] << '\n';
    }
}