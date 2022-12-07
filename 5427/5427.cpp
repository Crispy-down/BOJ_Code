#include <bits/stdc++.h>
#define X first 
#define Y second
using namespace std;

int T;
int N,M;
char board[1001][1001];
int sang_dist[1001][1001];
int fire_dist[1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 0;t<T;t++) {
        bool flag = false;
        cin >> M >> N;
        queue <pair<int,int>> fire_Q = {},sang_Q = {};

        for(int a = 0;a<N;a++) {
            fill(sang_dist[a],sang_dist[a] + M,-1);
            fill(fire_dist[a],fire_dist[a] + M,-1);
        }

        string temp;
        for(int i = 0;i<N;i++) {
            cin >> temp;
            for(int j = 0;j<M;j++) {
                board[i][j] = temp[j];
                if(temp[j] == '@') {
                    sang_dist[i][j] = 0;
                    sang_Q.push({i,j});
                }
                if(temp[j] == '*') {
                    fire_dist[i][j] = 0;
                    fire_Q.push({i,j});
                }
            }
        }

        while(!fire_Q.empty()) {
            auto cur = fire_Q.front();
            fire_Q.pop();
            for(int dir = 0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx >= N || nx < 0 || ny < 0 || ny >= M) {
                    continue;
                }
                if(board[nx][ny] == '#') {
                    continue;
                }
                if(fire_dist[nx][ny] >= 0) {
                    continue;
                }
                fire_dist[nx][ny] = fire_dist[cur.X][cur.Y] + 1;
                fire_Q.push({nx,ny});
            }
        }

        while((!sang_Q.empty()) && !flag) {
            auto cur = sang_Q.front();
            sang_Q.pop();
            for(int dir = 0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    cout << sang_dist[cur.X][cur.Y] + 1 << '\n';
                    flag = true;
                    break;
                }
                if(board[nx][ny] == '#' || sang_dist[nx][ny] != -1) {
                    continue;
                }
                if(fire_dist[nx][ny] <= sang_dist[cur.X][cur.Y] + 1 && fire_dist[nx][ny] >= 0) {
                    // fire == -1 일때는 지나가야함.
                    continue;
                }
                sang_dist[nx][ny] = sang_dist[cur.X][cur.Y] + 1;
                sang_Q.push({nx,ny});
            }
        }

        if(!flag) {
            cout << "IMPOSSIBLE" << '\n';
        }
    }


    return 0;
}
// 불에 대한 BFS를 먼저 돌리고 난 뒤,
// 상근이에 대한 BFS를 돌릴 때,
// 불이 옮겨가기 전 시간대에 대해 도달 할 수 있으면 돌린다.