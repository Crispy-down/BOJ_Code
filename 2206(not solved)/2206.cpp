#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N,M;
int board[1002][1002];
int dis[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0;i<N;i++) {
        string temp;
        cin >> temp;
        for(int j = 0;j<M;j++) {
            board[i][j] = temp[j] - '0';
        }
    }

    queue <pair<int,int>> Q;
    Q.push({0,0});
    fill(&dis[0][0],&dis[1001][1002],-1);
    dis[0][0] = 0;







    return 0;
}