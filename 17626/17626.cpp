#include <bits/stdc++.h>
using namespace std;

int N;
int board[50005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int check;
    int min_num;

    board[1] = 1;

    for(int i = 2;i<=N;i++) {
        board[i] = board[i-1] + 1;
        for(int j = 1; j*j <= i;j++) {
            board[i] = min(board[i], board[i-(j*j)] + 1);
        }
    }

    cout << board[N];
}

// ó�� �߻� : 
// N���� ���� ����� ���� �������� ���Ͽ� ������ ���ϴ�� ���� �����ϴ� �� �˾���
// * dp ���̺� dp[N]�� �ǹ̸� ����� �������� �ʰ� Ǯ��� �� �κ��� ���ľ���.

// dp[N] => N�̶�� ���ڰ� ������ �׶��� ��Ÿ�� �� �ִ� ���������� �ּ� �� ����
// if, N = 101�϶�?
// dp[101] = dp[1] + dp[100]
//         = dp[4] + dp[97]
//         = dp[9] + dp[92] .. ó�� N�� �Ѿ�� �ʴ� �������� �����ؼ�
// dp[k] + dp[N-k] (k == ������)�� set �� �ּڰ��� dp[N]�� ����.

// * for(int i = 1;i*i < j;i++)
// == j�� ���� �ʴ� ���� �� i�� ����� �ִ� �ִ��� ������ ��������.