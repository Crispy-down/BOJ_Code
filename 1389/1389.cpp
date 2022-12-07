#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; // 계산과정에서 INF 2개 더할때 int overflow 기피하기 위함.
int d[105][105]; // 인접행렬 형식,최단거리 테이블
int N,M;
int min_bacon = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int a,b;

    fill(&d[0][0],&d[104][105],INF);
    for(int i = 0;i<M;i++) {
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for(int i = 1;i<=N;i++) {
        d[i][i] = 0;
    }

    for(int k = 1;k<=N;k++) {
        for(int i = 1;i<=N;i++) {
            for(int j = 1;j<=N;j++) {
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }

    int temp = 0;
    int maxi = 1000000;
    for(int i = 1;i<=N;i++) {
        for(int j = 1;j<=N;j++) {
           temp += d[i][j];
        }
        if(temp < maxi) {
            maxi = temp;
            min_bacon = i;
        }
        temp = 0;
    }

    cout << min_bacon;

    return 0;
}