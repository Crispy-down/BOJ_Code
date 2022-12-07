#include <bits/stdc++.h>
#define X first 
#define Y second
using namespace std;

int N,M,K;
int max_area = 0;
int board[102][102]; // initialized by 0
int vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    int a,b;

    for(int i = 0;i<K;i++) {
        cin >> a >> b;
        board[a][b] = 1;
    }

    int area;

    for(int i = 1;i<=N;i++) {
        for(int j = 1;j<=M;j++) {
            if(board[i][j] && vis[i][j] == 0) {
                queue <pair<int,int>> Q;
                Q.push({i,j});
                vis[i][j] = 1;
                area = 1;
                while(!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx <= 0 || nx > N || ny <= 0 || ny > M) {
                            continue;
                        }
                        if(vis[nx][ny] || board[nx][ny] != 1) {
                            continue;
                        }
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                        area++;
                    }
                }
                max_area = max(area,max_area);
            }
        }
    }
    cout << max_area;
    return 0;
}