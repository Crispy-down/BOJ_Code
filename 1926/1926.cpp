#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N,M;
int board[502][502];
bool vis[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0;i<N;i++) {
        for(int k = 0;k<M;k++) {
            cin >> board[i][k];
        }
    }

    int paint_cnt = 0; // 그림 개수들 저장 - 초기점 찾을때 마다 +1
    int paint_max = 0; // 그림의 최대값

    for(int i = 0;i<N;i++) {
        for(int k = 0;k < M;k++) { // 초기 좌표값이 지정되지 않았다 => for문으로 돌려서 진행 (N*M * N*M)
            if(board[i][k] == 0 || vis[i][k]) {
                continue;
            } // 칸의 값이 0이거나 이미 방문한 좌표라면 제외
            queue <pair<int,int>> Q;
            vis[i][k] = 1; // 초기점 방문 표기
            Q.push({i,k}); // 초기점 삽입
            paint_cnt++; // 그림 개수 (초기점 찾을때마다 +)
            int paint_a = 0; // 넓이 초기화
            while(!Q.empty()) {
                pair<int,int> cur = Q.front();
                Q.pop(); // 방문
                paint_a++; // 넓이 증가
                for(int dir = 0;dir <4;dir++) { //상하좌우 탐색
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) { // 범위 제한
                        continue;
                    }
                    if(vis[nx][ny] || board[nx][ny] != 1) { // 방문했거나 1이 아닌 부문은 제외
                        continue;
                    }
                    vis[nx][ny] = 1; // 방문 표기
                    Q.push({nx,ny}); // 좌표 삽입
                }
            }
            paint_max = max(paint_a,paint_max); // 최대값 삽입
        }
    }

    cout << paint_cnt << '\n';
    cout << paint_max;

    return 0;
}