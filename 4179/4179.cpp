#include <bits/stdc++.h>
#define X first 
#define Y second
using namespace std;

int N,M;
char board[1002][1002]; 
int bool_dist[1002][1002]; // initialize by 0
int zihun_dist[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    string input;

    queue <pair<int,int>> bool_Q;
    queue <pair<int,int>> zihun_Q;

    for(int i = 0;i<N;i++) {
        fill(bool_dist[i],bool_dist[i] + M,-1); // -1으로 처리
        fill(zihun_dist[i],zihun_dist[i] + M,-1);
    }

    for(int i = 0;i<N;i++) {
        cin >> input;
        for(int j = 0;j<M;j++) {
            board[i][j] = input[j];
            if(board[i][j] == 'F') {
                bool_Q.push({i,j}); // 불 BFS 초기 좌표
                bool_dist[i][j] = 0; // 시작 구간
            }
            if(board[i][j] == 'J') {
                zihun_Q.push({i,j}); // 지훈 BFS 초기 좌표
                zihun_dist[i][j] = 0;
            }
        }
    }

    while(!bool_Q.empty()) {
        auto cur = bool_Q.front();
        bool_Q.pop();
        for(int dir = 0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            if(board[nx][ny] == '#' || bool_dist[nx][ny] >= 0) { // avoid visited part and wall(initialized by 0)
                continue;
            }
            bool_dist[nx][ny] = bool_dist[cur.X][cur.Y] + 1; // bool bool_dist update
            bool_Q.push({nx,ny});
        }
    } // bool BFS

    // zihun has to be avoid fire(bool_dist[nx][ny] 가 zihun[nx][ny] + 1 보다 같거나 작으면 불가능)

    while(!zihun_Q.empty()) {
        auto cur = zihun_Q.front();
        zihun_Q.pop();
        for(int dir = 0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) { // 통과한것.
                cout << zihun_dist[cur.X][cur.Y] + 1;
                return 0;
            }
            if(board[nx][ny] == '#' || zihun_dist[nx][ny] >= 0 ) { // 방문한곳 제외
                continue;
            }
            if(bool_dist[nx][ny] != -1 && bool_dist[nx][ny] <= zihun_dist[cur.X][cur.Y] + 1) { // 앞으로 탐색할 부문에 불이 번진 상태를 피함
                continue;
                // nx ny 가 앞으로 움직일 범위 ~ cur.X cur.Y 현재 위치 기점
            }
            zihun_dist[nx][ny] = zihun_dist[cur.X][cur.Y] + 1;
            zihun_Q.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";

}
// BFS distance 배열
// 0 = 시작지점 , -1 = 초기화 값 ~ 이외 조건따라 continue 조건 부여
// ex) dist[nx][ny] >= 0 -> 방문한 곳 제외
// 이 문제는 
// # 1.
// 불이 퍼진 시각을 계산(BFS)
// #2.
// 그 후 지훈의 입장에서 불의 dist 배열 기준,(77줄)
//(초기화값 제외, 불이 퍼진 시각보다 지훈 이동 시각이 작거나 같으면 이동 불가)
// #3.
// 또한, 가장자리에 접한 공간에서 탈출이 가능하다
// == 지훈 BFS 계산시 범위 밖으로 나갈수있다면 탈출이 가능한 것.
// 따라서 70줄 조건에서 현재 자리 기준 + 1 => 탈출 최단시간.