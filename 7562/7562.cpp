#include <bits/stdc++.h>
#define X first 
#define Y second 
using namespace std;

int T,I;
int s_x,s_y,f_x,f_y; // start x final x
int dis[302][302];
int dx[8] = {-2,-2,-1,1,2,2,1,-1}; // 8 point
int dy[8] = {-1,1,2,2,1,-1,-2,-2};

void reset() {
    fill(&dis[0][0],&dis[301][302],-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i = 0;i<T;i++) {
        reset();
        queue <pair<int,int>> Q;
        cin >> I;
        cin >> s_x >> s_y;
        cin >> f_x >> f_y;

        Q.push({s_x,s_y}); // start point
        dis[s_x][s_y] = 0;
        while(!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for(int dir = 0;dir<8;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= I || ny < 0 || ny >= I) {
                    continue;
                }
                if(dis[nx][ny] >= 0) {
                    continue;
                }
                dis[nx][ny] = dis[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
        cout << dis[f_x][f_y] << '\n';
    }

    return 0;
}