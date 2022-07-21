#include <bits/stdc++.h>
#define X first 
#define Y second
using namespace std;

int T,N,M,K;
int board[52][52];
int vis[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void reset() {
    fill(&board[0][0],&board[51][52],0); // 초기화(배추가 심어진 배열)
    fill(&vis[0][0],&vis[51][52],0); /// 초기화(방문한 배열)
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    int cab_x,cab_y;
    int ans = 0;

    for(int i = 0;i<T;i++) {
        cin >> M >> N >> K;

        for(int k = 0;k<K;k++) {
            cin >> cab_x >> cab_y;
            board[cab_x][cab_y] = 1; // 배추가 있는 곳
        }

        for(int a = 0;a<M;a++) {
            for(int b = 0;b<N;b++) {
                if(board[a][b] == 0 || vis[a][b] == 1) { // 배추가 없는 곳이거나 방문한 곳이라면 제외 , 초기 좌표 찾음
                    continue;
                }
                queue <pair<int,int>> Q;
                vis[a][b] = 1; // 방문 표시
                ans++; // 흰 지렁이 개수 = 초기 좌표 개수(탐색에 필요한)
                Q.push({a,b});
                while(!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= M || ny < 0 || ny >= N) {
                            continue;
                        }
                        if(board[nx][ny] == 0 || vis[nx][ny] == 1) { // 배추가 심어져 있지 않거나 방문한 좌표는 제외
                            continue;
                        }
                        vis[nx][ny] = 1; // 방문함 표시
                        Q.push({nx,ny});
                    }                
                } 
            }
        }
        cout << ans << '\n';
        ans = 0;
        reset();
    }
    return 0;
}