#include <bits/stdc++.h>
using namespace std;

int N;
int dp[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    dp[1] = 1;

    for(int i = 2;i<=100000;i++) {
        dp[i] = dp[i-1] + 1; // �켱, �������� 1�� �þ�� ������ + 1 (1���� ����) default������ �߰���
        for(int j = 1;j*j <= i;j++) {
            dp[i] = min(dp[i],dp[i - j*j] + 1); // ���� �ʿ�, N���� �������� �� ������ ���� �� �ּҰ��� ã��
            // ex )
            // N = 26
            // dp[26] = dp[1] + dp[25] = 1 + 1
            //        = dp[4] + dp[22] = 1 + dp[22] ~ ..
            //        = dp[9] + dp[17] = 1 + dp[17] ~ ..
            //        = dp[16] + dp[10] = 1 + dp[10] ~ ..
            //        = dp[25] + dp[1] = 1 + 1
        }
    }

    cout << dp[N];

}

// Dp[N] = ���� N�� �� ��Ÿ�� �� �ִ� ������ ���� �ּ� ����
// dp[1] = 1
// dp[2] = 1 + 1
// dp[3] = 1 + 1 + 1
// dp[4] = 1
// dp[5] = dp[4] + dp[1]
// dp[6] = dp[4] + dp[2]
//         = dp[1] + dp[5]
// dp[7] = dp[1] + dp[6]
// 	= dp[4] + dp[3]
// dp[8] = dp[1] + dp[7]
// 	= dp[4] + dp[4]
// dp[9] = 1