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
        fill(bool_dist[i],bool_dist[i] + M,-1); // -1���� ó��
        fill(zihun_dist[i],zihun_dist[i] + M,-1);
    }

    for(int i = 0;i<N;i++) {
        cin >> input;
        for(int j = 0;j<M;j++) {
            board[i][j] = input[j];
            if(board[i][j] == 'F') {
                bool_Q.push({i,j}); // �� BFS �ʱ� ��ǥ
                bool_dist[i][j] = 0; // ���� ����
            }
            if(board[i][j] == 'J') {
                zihun_Q.push({i,j}); // ���� BFS �ʱ� ��ǥ
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

    // zihun has to be avoid fire(bool_dist[nx][ny] �� zihun[nx][ny] + 1 ���� ���ų� ������ �Ұ���)

    while(!zihun_Q.empty()) {
        auto cur = zihun_Q.front();
        zihun_Q.pop();
        for(int dir = 0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) { // ����Ѱ�.
                cout << zihun_dist[cur.X][cur.Y] + 1;
                return 0;
            }
            if(board[nx][ny] == '#' || zihun_dist[nx][ny] >= 0 ) { // �湮�Ѱ� ����
                continue;
            }
            if(bool_dist[nx][ny] != -1 && bool_dist[nx][ny] <= zihun_dist[cur.X][cur.Y] + 1) { // ������ Ž���� �ι��� ���� ���� ���¸� ����
                continue;
                // nx ny �� ������ ������ ���� ~ cur.X cur.Y ���� ��ġ ����
            }
            zihun_dist[nx][ny] = zihun_dist[cur.X][cur.Y] + 1;
            zihun_Q.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";

}
// BFS distance �迭
// 0 = �������� , -1 = �ʱ�ȭ �� ~ �̿� ���ǵ��� continue ���� �ο�
// ex) dist[nx][ny] >= 0 -> �湮�� �� ����
// �� ������ 
// # 1.
// ���� ���� �ð��� ���(BFS)
// #2.
// �� �� ������ ���忡�� ���� dist �迭 ����,(77��)
//(�ʱ�ȭ�� ����, ���� ���� �ð����� ���� �̵� �ð��� �۰ų� ������ �̵� �Ұ�)
// #3.
// ����, �����ڸ��� ���� �������� Ż���� �����ϴ�
// == ���� BFS ���� ���� ������ �������ִٸ� Ż���� ������ ��.
// ���� 70�� ���ǿ��� ���� �ڸ� ���� + 1 => Ż�� �ִܽð�.