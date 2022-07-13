#include <iostream>
using namespace std;

int dp[301];

int main() {
    int n;
    cin >> n;

    int *stair = new int[n];
    for(int i = 0;i<n;i++) {
        cin >> stair[i];
    }

    dp[0] = stair[0]; // n == 1
    dp[1] = max(stair[1],stair[0] + stair[1]); // n == 2
    dp[2] = max(stair[0] + stair[2],stair[1] + stair[2]); // n == 3

    for(int i = 3;i<301;i++) {
        dp[i] = max(dp[i-2] + stair[i],dp[i-3] + stair[i-1] + stair[i]);
    }

    cout << dp[n-1] << endl;

    delete[] stair;
    return 0;
}