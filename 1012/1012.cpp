#include <bits/stdc++.h>
#define X first 
#define Y second
using namespace std;

int T,N,M,K;
int board[52][52];
int vis[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void reset() {
    fill(&board[0][0],&board[51][52],0); // �ʱ�ȭ(���߰� �ɾ��� �迭)
    fill(&vis[0][0],&vis[51][52],0); /// �ʱ�ȭ(�湮�� �迭)
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    int cab_x,cab_y;
    int ans = 0;

    for(int i = 0;i<T;i++) {
        cin >> M >> N >> K;

        for(int k = 0;k<K;k++) {
            cin >> cab_x >> cab_y;
            board[cab_x][cab_y] = 1; // ���߰� �ִ� ��
        }

        for(int a = 0;a<M;a++) {
            for(int b = 0;b<N;b++) {
                if(board[a][b] == 0 || vis[a][b] == 1) { // ���߰� ���� ���̰ų� �湮�� ���̶�� ���� , �ʱ� ��ǥ ã��
                    continue;
                }
                queue <pair<int,int>> Q;
                vis[a][b] = 1; // �湮 ǥ��
                ans++; // �� ������ ���� = �ʱ� ��ǥ ����(Ž���� �ʿ���)
                Q.push({a,b});
                while(!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= M || ny < 0 || ny >= N) {
                            continue;
                        }
                        if(board[nx][ny] == 0 || vis[nx][ny] == 1) { // ���߰� �ɾ��� ���� �ʰų� �湮�� ��ǥ�� ����
                            continue;
                        }
                        vis[nx][ny] = 1; // �湮�� ǥ��
                        Q.push({nx,ny});
                    }                
                } 
            }
        }
        cout << ans << '\n';
        ans = 0;
        reset();
    }
    return 0;
}