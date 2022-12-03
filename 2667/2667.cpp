#include <bits/stdc++.h>
#define X first 
#define Y second
using namespace std;

int N;
char board[27][27];
int vis[27][27];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector <int> ans_area;
int ans_cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string temp;
    for(int i = 0;i<N;i++) {
        cin >> temp;
        for(int j = 0;j<N;j++) {
            board[i][j] = temp[j];
        }
    }

    queue <pair<int,int>> Q;
    int area;

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            if(board[i][j] == '1' && vis[i][j] == 0) { // 1 + not visited
                Q.push({i,j});
                vis[i][j] = 1; // visited
                ans_cnt++; // danzi cnt
                area = 1; // for area
                while(!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
                            continue;
                        }
                        if(board[nx][ny] == '0' || vis[nx][ny] == 1) {
                            continue;
                        }
                        vis[nx][ny] = 1;
                        area++;
                        Q.push({nx,ny});
                    }
                }
                ans_area.push_back(area);         
            }
        }
    }


    sort(ans_area.begin(),ans_area.end());

    cout << ans_cnt << '\n';
    for(int i = 0;i<ans_area.size();i++) {
        cout << ans_area[i] << '\n';
    }

    return 0;
}