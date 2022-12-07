#include <bits/stdc++.h>
using namespace std;

int N,M;
char board[52][52];
int vis[52][52];
int flat_cnt = 0;
int up_cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    fill(&vis[0][0],&vis[51][52],-1);

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            cin >> board[i][j];
        }
    }

    queue <int> Q;

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            if(board[i][j] == '-' && vis[i][j] == -1) {
                Q.push(j);
                flat_cnt++;
                vis[i][j] = 1;
                while(!Q.empty()) {
                    int cur = Q.front();
                    Q.pop();
                    for(int ny : {cur+1,cur-1}) {
                        if(ny < 0 || ny >= M) {
                            continue;
                        }
                        if(board[i][ny] == '|' || vis[i][ny] != -1) {
                            continue;
                        }
                        vis[i][ny] = 1;
                        Q.push(ny);
                    }
                }
            }
            else if(board[i][j] == '|' && vis[i][j] == -1) {
                Q.push(i);
                up_cnt++;
                vis[i][j] = 1;
                while(!Q.empty()) {
                    int cur = Q.front();
                    Q.pop();
                    for(int nx : {cur+1,cur-1}) {
                        if(nx < 0 || nx >= N) {
                            continue;
                        }
                        if(board[nx][j] == '-' || vis[nx][j] != -1) {
                            continue;
                        }
                        vis[nx][j] = 1;
                        Q.push(nx);
                    }
                }
            }
        }
    }

    cout << flat_cnt + up_cnt;

    return 0;
}