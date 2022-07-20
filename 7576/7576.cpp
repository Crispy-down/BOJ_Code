#include <bits/stdc++.h>
#define X first 
#define Y second 
using namespace std;

int N,M;
int board[1002][1002];
int dist[1002][1002]; // ��¥ ���� �迭 0���� �ʱ�ȭ
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
            if(board[i][j] == 1) { // �ʱⰪ�� ���������� ���ÿ� BFS�ؾ��ϴ� Ž���ϸ鼭 �̸� ť�� ����
                Q.push({i,j});
            }
            if(board[i][j] == 0) { //���� ���� �丶�� ������� �Ÿ����� �ʱ�ȭ��
                dist[i][j] = -1; // �Ÿ� �ʱ�ȭ
            }
            // ���߿� BFS ���ϰ� ���� -1���� �����ִٸ�, �丶�䰡 �� ���� ���� ����.

        }
    }

    while(!Q.empty()) {
        pair <int,int> cur = Q.front();
        Q.pop();
        for(int dir = 0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) { // ���� üũ
                continue;
            }
            if(dist[nx][ny] >= 0) { // �̹� �湮�� ��ǥ ����~ dist�迭�� ���� -1�϶��� Ž��
                continue;
            }
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // �Ÿ� ������Ʈ(��¥)
            Q.push({nx,ny}); // �̶� �Ÿ������� Queue�� ���δ�.
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

// ������������ �ʱⰪ���� BFS�� �������ϴµ�
// ���������� for������ �ʱⰪ�� ã�� BFS�� ������
// O(NM) * O(NM) (BFS * �ִ� �ʱ� �丶�� ����)
// => O(N^2 * M^2)�� ��Ǯ�� �� �ִ�.
// �������� �������� BFS�� ���� �� �־���Ѵ�.
// ���� �ʹ� �Է°�����
// ���� �丶�䰪�� ĭ�� �������� Q�� ������
// ���ÿ� BFS�� �����ؾ��Ѵ�.


// 7576�� �丶��

// ���� �丶�� = 1
// ���� ���� �丶�� = 0
// �丶�䰡 ������� ���� ĭ = -1

// ���� �� �Ϸ簡 ������ ���� �丶�� ���� �����¿� ���� (1)
// => ��� ���� �������� �ּҳ�¥�� ����ؾ���
// => dist �迭 ���� ~ ��¥�� ����(MAX)��
// *dist �迭�� ó���� 0���� �ʱ�ȭ.
// �� ����, �ʱⰪ�� ��������
// �ʱⰪ���� ����Ž������ Queue�� �̸� �� ����
// �� �������� ���� �丶��� Enqueue
// ���� ���� �丶��� dist �迭�� -1 set
// �丶�䰡 ������� ���� ĭ�� 0���� set

// BFS �� �ϰ� ����,
// dist �迭�� -1�� �����ִٸ� => �������ִ� �丶���ε� ������
// = -1 ���.


// ** Queue���� ��¥��(�Ÿ���)���� Enqueue�� �����.(pop�Ǹ鼭 ��¥�� �þ�� ����)
