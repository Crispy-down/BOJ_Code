#include <bits/stdc++.h>
#define X first 
#define Y second
using namespace std;

int N;
int RGB_ans = 0;
int RB_ans = 0;
char board[102][102];
int RGB_vis[102][102];
int RB_vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string temp;

    for(int i = 0;i<N;i++) {
        cin >> temp;
        for(int j = 0;j<N;j++) {
            board[i][j] = temp[j];
        }
    }
    queue <pair<int,int>> Q;

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            if(RGB_vis[i][j] == 0) {
                Q.push({i,j});
                RGB_vis[i][j] = 1;
                RGB_ans++; // �ʱ��� �߰� => ���� ���� ����
                while(!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
                            continue;
                        }
                        if(board[nx][ny] != board[i][j] || RGB_vis[nx][ny] > 0) { 
                            // �ʱⰪ�� ���� �ٸ������� Ž�� X
                            // �湮�� ���� Ž�� x
                            continue;
                        }
                        RGB_vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }        
        }
    }

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            if(RB_vis[i][j] == 0) {
                Q.push({i,j});
                char color = board[i][j]; // �� ����
                RB_vis[i][j] = 1;
                RB_ans++; // �ʱ��� �߰� => ���� ���� ����
                while(!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
                            continue;
                        }
                        if(RB_vis[nx][ny] > 0) { 
                            // �湮�� ���� Ž�� x
                            continue;
                        }
                        if(color == 'R' || color == 'G') { // �ʱⰪ�� ������ ���� �ƴ� �ʷ�
                            if(board[nx][ny] == 'B') { // Ž���� �Ķ����� ĭ�� Ž������ �ʴ´�.
                                continue;
                            }
                        }
                        else { // �ʱⰪ�� ������ �Ķ��̶��,
                            if(board[nx][ny] == 'R' || board[nx][ny] == 'G') { // Ž���� ����/�ʷϻ��� ĭ�� Ž������ �ʴ´�.
                                continue;
                            }
                        }
                        RB_vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }        
        }
    }

    cout << RGB_ans << " " << RB_ans;

    return 0;
}