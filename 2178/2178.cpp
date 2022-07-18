#include <bits/stdc++.h>
#define X first 
#define Y second

using namespace std;

int N,M;
int board[102][102];
int dist[102][102]; // 거리를 표현하는 배열
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    string temp;

    for(int i = 0;i<N;i++) {
        cin >> temp;
        for(int k = 0;k<M;k++) {
            board[i][k] = temp[k]-'0'; // char to int
        }
    }

    fill(&dist[0][0],&dist[101][102],-1); //2차원 배열 초기화
 
    queue <pair<int,int>> Q;
    dist[0][0] = 0; //초기 거리
    Q.push({0,0});

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir = 0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) { // 범위 체크
                continue;
            }
            if(board[nx][ny] == 0 || dist[nx][ny] >= 0) { // board 0값과 방문안한곳 제외
                continue;
            }
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; //제일 중요한 포인트
            // 퍼져서 나가는걸 생각해보면 기준점 잡고
            // 1씩 거리 늘어남
            Q.push({nx,ny});
        }
    }

    cout << dist[N-1][M-1] + 1;
    return 0;
}
// BFS 유형 두번째, 최단거리 찾기
// 하나의 초기 기준점에서
// 상하좌우 탐색을 진행할 시
// 상하좌우에 대해서 dist[nx][ny] = dist[cur.X][cur.Y] + 1 (1씩 거리가 늘어난다)
// 여기서는 vis 배열을 사용하지 않고, dist 배열을 초기화하여
// 초기화는 fill(&arr[0][0],&arr[N-1][M],초기화값 -1) 사용
// 방문한걸 dist를 활용하여 (방문했다면 거리 표시,0이상) 표기하였다