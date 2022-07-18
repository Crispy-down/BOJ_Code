#include <bits/stdc++.h>
#define X first 
#define Y second

using namespace std;

int N,M;
int board[102][102];
int dist[102][102]; // �Ÿ��� ǥ���ϴ� �迭
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

    fill(&dist[0][0],&dist[101][102],-1); //2���� �迭 �ʱ�ȭ
 
    queue <pair<int,int>> Q;
    dist[0][0] = 0; //�ʱ� �Ÿ�
    Q.push({0,0});

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir = 0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) { // ���� üũ
                continue;
            }
            if(board[nx][ny] == 0 || dist[nx][ny] >= 0) { // board 0���� �湮���Ѱ� ����
                continue;
            }
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; //���� �߿��� ����Ʈ
            // ������ �����°� �����غ��� ������ ���
            // 1�� �Ÿ� �þ
            Q.push({nx,ny});
        }
    }

    cout << dist[N-1][M-1] + 1;
    return 0;
}
// BFS ���� �ι�°, �ִܰŸ� ã��
// �ϳ��� �ʱ� ����������
// �����¿� Ž���� ������ ��
// �����¿쿡 ���ؼ� dist[nx][ny] = dist[cur.X][cur.Y] + 1 (1�� �Ÿ��� �þ��)
// ���⼭�� vis �迭�� ������� �ʰ�, dist �迭�� �ʱ�ȭ�Ͽ�
// �ʱ�ȭ�� fill(&arr[0][0],&arr[N-1][M],�ʱ�ȭ�� -1) ���
// �湮�Ѱ� dist�� Ȱ���Ͽ� (�湮�ߴٸ� �Ÿ� ǥ��,0�̻�) ǥ���Ͽ���