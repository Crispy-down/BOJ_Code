#include <bits/stdc++.h>
using namespace std;

int N;
int board[70][70];

void solve(int x,int y,int size) {
    if(size <= 1) { // 1개남은 경우 => 출력만 하기
        cout << board[x][y];
        return;
    }

    int num = board[x][y];
    bool div = false;

    for(int i = x;i<x + size;i++) { // 파라미터 기준으로, 해당 범위 내에서 검사
        for(int j = y;j<y + size;j++) {
            if(num != board[i][j]) {
                div = true; // need to divide
                break;
            }
        }
    }

    if(div) { // need to divide
        cout << "(";
        solve(x,y,size/2); //1사분면
        solve(x,y+size/2,size/2); //2사분면
        solve(x+size/2,y,size/2); //3사분면
        solve(x+size/2,y+size/2,size/2); //4사분면
        cout << ")";
    }
    else { // range in board is same
        cout << board[x][y];
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string temp;
    for(int i = 0;i<N;i++) {
        cin >> temp;
        for(int k = 0;k<N;k++) {
            board[i][k] = temp[k] - '0';
        }
    }

    solve(0,0,N);

}