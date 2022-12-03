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

    int paint_cnt = 0; // �׸� ������ ���� - �ʱ��� ã���� ���� +1
    int paint_max = 0; // �׸��� �ִ밪

    for(int i = 0;i<N;i++) {
        for(int k = 0;k < M;k++) { // �ʱ� ��ǥ���� �������� �ʾҴ� => for������ ������ ���� (N*M * N*M)
            if(board[i][k] == 0 || vis[i][k]) {
                continue;
            } // ĭ�� ���� 0�̰ų� �̹� �湮�� ��ǥ��� ����
            queue <pair<int,int>> Q;
            vis[i][k] = 1; // �ʱ��� �湮 ǥ��
            Q.push({i,k}); // �ʱ��� ����
            paint_cnt++; // �׸� ���� (�ʱ��� ã�������� +)
            int paint_a = 0; // ���� �ʱ�ȭ
            while(!Q.empty()) {
                pair<int,int> cur = Q.front();
                Q.pop(); // �湮
                paint_a++; // ���� ����
                for(int dir = 0;dir <4;dir++) { //�����¿� Ž��
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) { // ���� ����
                        continue;
                    }
                    if(vis[nx][ny] || board[nx][ny] != 1) { // �湮�߰ų� 1�� �ƴ� �ι��� ����
                        continue;
                    }
                    vis[nx][ny] = 1; // �湮 ǥ��
                    Q.push({nx,ny}); // ��ǥ ����
                }
            }
            paint_max = max(paint_a,paint_max); // �ִ밪 ����
        }
    }

    cout << paint_cnt << '\n';
    cout << paint_max;

    return 0;
}