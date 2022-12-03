#include <bits/stdc++.h>
using namespace std;

char board[32][32][32];
int dis[32][32][32];
int L,R,C;
int dL[6] = {1,-1,0,0,0,0};
int dR[6] = {0,0,0,0,-1,1};
int dC[6] = {0,0,1,-1,0,0};
int eL,eR,eC;

void reset() {
    for(int i = 0;i<L;i++) {
        for(int j = 0;j<R;j++) {
            for(int k = 0;k<C;k++) {
                dis[i][j][k] = -1;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> L >> R >> C;

        if(L == 0) {
            return 0;
        }

        reset();

        queue <tuple <int,int,int>> Q;

        for(int i = 0;i<L;i++) {
            for(int j = 0;j<R;j++) {
                for(int k = 0;k<C;k++) {
                    cin >> board[i][j][k];
                    if(board[i][j][k] == 'S') {
                        Q.push({i,j,k});
                        dis[i][j][k] = 0;
                    }
                    if(board[i][j][k] == 'E') {
                        eL = i;
                        eR = j;
                        eC = k;
                    }
                }
            }
        }

        while(!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for(int dir = 0;dir<6;dir++) {
                int nL = get<0>(cur) + dL[dir];
                int nR = get<1>(cur) + dR[dir];
                int nC = get<2>(cur) + dC[dir];
                if(nL < 0 || nL >= L || nR < 0 || nR >= R || nC < 0 || nC >= C) {
                    continue;
                }
                if(dis[nL][nR][nC] >= 0 || board[nL][nR][nC] == '#') {
                    continue;
                }
                dis[nL][nR][nC] = dis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                Q.push({nL,nR,nC});
            }
        }

        if(dis[eL][eR][eC] >= 0) {
            cout << "Escaped in " << dis[eL][eR][eC] << " minute(s)." << '\n';
        }
        else {
            cout << "Trapped!" << '\n';
        }

    }
}

// tuple를 활용하여 3차원 배열을 표현하였다.
// 상하동서북남 방향 
// int dL[6] = {1,-1,0,0,0,0};
// int dR[6] = {0,0,0,0,-1,1};
// int dC[6] = {0,0,1,-1,0,0};