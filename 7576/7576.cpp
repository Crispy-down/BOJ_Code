#include <bits/stdc++.h>
#define X first 
#define Y second 
using namespace std;

int N,M;
int board[1002][1002];
int dist[1002][1002]; // 날짜 저장 배열 0으로 초기화
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    queue <pair<int,int>> Q;

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) { // 초기값이 여러개에서 동시에 BFS해야하니 탐색하면서 미리 큐에 삽입
                Q.push({i,j});
            }
            if(board[i][j] == 0) { //익지 않은 토마토 대상으로 거리값을 초기화함
                dist[i][j] = -1; // 거리 초기화
            }
            // 나중에 BFS 다하고 나서 -1값이 남아있다면, 토마토가 다 익지 않은 상태.

        }
    }

    while(!Q.empty()) {
        pair <int,int> cur = Q.front();
        Q.pop();
        for(int dir = 0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) { // 범위 체크
                continue;
            }
            if(dist[nx][ny] >= 0) { // 이미 방문한 좌표 제외~ dist배열의 값이 -1일때만 탐색
                continue;
            }
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 거리 업데이트(날짜)
            Q.push({nx,ny}); // 이때 거리순으로 Queue에 쌓인다.
        }
    }

    int ans = 0;
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            if(dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans,dist[i][j]);
        }
    }
    cout << ans;

}

// 여러점에서의 초기값에서 BFS를 돌려야하는데
// 이전에서의 for문으로 초기값을 찾아 BFS을 돌리면
// O(NM) * O(NM) (BFS * 최대 초기 토마토 개수)
// => O(N^2 * M^2)로 안풀릴 수 있다.
// 시작점이 여러개인 BFS를 돌릴 수 있어야한다.
// 따라서 초반 입력값에서
// 익은 토마토값의 칸을 기준으로 Q에 넣은뒤
// 동시에 BFS를 진행해야한다.


// 7576번 토마토

// 익은 토마토 = 1
// 익지 않은 토마토 = 0
// 토마토가 들어있지 않은 칸 = -1

// 보관 후 하루가 지나면 익은 토마토 인접 상하좌우 익음 (1)
// => 모두 익을 때까지의 최소날짜를 출력해야함
// => dist 배열 선언 ~ 날짜를 구함(MAX)값
// *dist 배열을 처음에 0으로 초기화.
// 그 다음, 초기값이 여러개니
// 초기값들을 완전탐색으로 Queue에 미리 다 넣음
// 그 과정에서 익은 토마토는 Enqueue
// 익지 않은 토마토는 dist 배열에 -1 set
// 토마토가 들어있지 않은 칸은 0으로 set

// BFS 다 하고 나서,
// dist 배열에 -1이 남아있다면 => 익을수있는 토마토인데 안익음
// = -1 출력.


// ** Queue에는 날짜순(거리순)으로 Enqueue가 진행됨.(pop되면서 날짜가 늘어나기 때문)
