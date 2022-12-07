#include <bits/stdc++.h>
using namespace std;

int N;
int board[70][70];

void solve(int x,int y,int size) {
    if(size <= 1) { // 1������ ��� => ��¸� �ϱ�
        cout << board[x][y];
        return;
    }

    int num = board[x][y];
    bool div = false;

    for(int i = x;i<x + size;i++) { // �Ķ���� ��������, �ش� ���� ������ �˻�
        for(int j = y;j<y + size;j++) {
            if(num != board[i][j]) {
                div = true; // need to divide
                break;
            }
        }
    }

    if(div) { // need to divide
        cout << "(";
        solve(x,y,size/2); //1��и�
        solve(x,y+size/2,size/2); //2��и�
        solve(x+size/2,y,size/2); //3��и�
        solve(x+size/2,y+size/2,size/2); //4��и�
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