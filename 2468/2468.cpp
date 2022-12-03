#include <bits/stdc++.h>
#define X first 
#define Y second
using namespace std;

int N;
int h_max = 0; // 높이 최대값
int max_area = 0; // 영역 최대값
int board[102][102];
int vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void reset() {
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            vis[i][j] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    reset();

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            cin >> board[i][j];
            h_max = max(h_max,board[i][j]); // max_height in board
        }
    }

    for(int i = 0;i<h_max;i++) { // 높이 0 ~ 최대값 BFS
        int temp_area = 0;
        queue <pair<int,int>> Q;
        for(int a = 0;a<N;a++) { // 높이 값에 대한 BFS
            for(int b = 0;b<N;b++) {
                if(board[a][b] > i && vis[a][b] == -1) { // 높이 보다 높고 방문안한 노드
                    Q.push({a,b});
                    vis[a][b] = 1;
                    temp_area++;
                    while(!Q.empty()) {
                        auto cur = Q.front();
                        Q.pop();
                        for(int dir = 0;dir<4;dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
                                continue;
                            }
                            if(vis[nx][ny] > 0 || board[nx][ny] <= i) { // 방문한 좌표 or 높이 해당 특정 높이보다 크면 방문 금지
                                continue;
                            }
                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        } 
        max_area = max(temp_area,max_area);
        reset();
    }

    cout << max_area;
    return 0;
}

// 브루트포스 + BFS

// 특정 높이 0 ~ 최대값까지의 BFS를 돌려  안전 영역을 구하면 된다.

// 특정 높이에 대해 높은 높이들로의 BFS를 돌리면 안전 구역이 구해진다.