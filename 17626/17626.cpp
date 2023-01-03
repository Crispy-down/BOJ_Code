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

// 처음 발상 : 
// N기준 가장 가까운 곳의 제곱수를 구하여 일정한 패턴대로 수가 존재하는 줄 알았음
// * dp 테이블 dp[N]의 의미를 제대로 지정하지 않고 풀었어서 이 부분을 고쳐야함.

// dp[N] => N이라는 숫자가 있을때 그때의 나타낼 수 있는 제곱수들의 최소 합 개수
// if, N = 101일땐?
// dp[101] = dp[1] + dp[100]
//         = dp[4] + dp[97]
//         = dp[9] + dp[92] .. 처럼 N을 넘어가지 않는 제곱수에 한정해서
// dp[k] + dp[N-k] (k == 제곱수)의 set 중 최솟값이 dp[N]에 들어간다.

// * for(int i = 1;i*i < j;i++)
// == j을 넘지 않는 범위 내 i로 만들수 있는 최대의 제곱수 범위까지.