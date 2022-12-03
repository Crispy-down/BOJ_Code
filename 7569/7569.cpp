#include <bits/stdc++.h>
using namespace std;

int N,M,H;
int board[102][102][102];
int dis[102][102][102];
int dz[6] = {1,-1,0,0,0,0};
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,-1,1,0,0};

void reset() {
    for(int z = 0;z<H;z++) {
        for(int x = 0;x<N;x++) {
            for(int y = 0;y<M;y++) {
                dis[z][x][y] = -1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    reset();

    queue <tuple <int,int,int>> Q;

    for(int z = 0;z<H;z++) {
        for(int x = 0;x<N;x++) {
            for(int y = 0;y<M;y++) {
                cin >> board[z][x][y];
                if(board[z][x][y] == 1) {
                    Q.push({z,x,y});
                    dis[z][x][y] = 0;
                }
                if(board[z][x][y] == -1) {
                    dis[z][x][y] = -2;
                }
            }
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for(int dir = 0;dir<6;dir++) {
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if(nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            if(board[nz][nx][ny] == -1 || dis[nz][nx][ny] >= 0) {
                continue;
            }
            dis[nz][nx][ny] = dis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({nz,nx,ny});
        } 
    }

    int max_day = 0;

    for(int z = 0;z<H;z++) {
        for(int x = 0;x<N;x++) {
            for(int y = 0;y<M;y++) {
                if(dis[z][x][y] == -1) {
                    cout << -1;
                    return 0;
                }
                max_day = max(max_day,dis[z][x][y]);
            }
        }
    }

    cout << max_day;
    

}