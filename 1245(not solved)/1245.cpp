#include <bits/stdc++.h>
#define X first 
#define Y second
using namespace std;

int N,M;
int mount_cnt = 0;
int board[102][102];
int vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    fill(&vis[0][0],&vis[101][102],-1);

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            cin >> board[i][j];
        }
    }

    queue <pair<int,int>> Q;

    int mount_h;

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            if(board[i][j] > 0 && vis[i][j] == -1) {
                Q.push({i,j});
                mount_h = board[i][j];
                mount_cnt++;
                vis[i][j] = 1;
                while(!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
                            continue;
                        }
                        if(board[nx][ny] == 0 || vis[nx][ny] != -1) {
                            continue;
                        }
                        if(board[nx][ny] > mount_h) {
                            continue;
                        }
                        vis[nx][ny] = 1;
                        mount_h = board[nx][ny];
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }

    cout << mount_cnt;

    return 0;
}