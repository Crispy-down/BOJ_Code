#include <bits/stdc++.h>
using namespace std;

int N,K;
int dis[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    fill(dis,dis+100001,-1);

    queue <int> Q;
    Q.push(N);
    dis[N] = 0;

    while(dis[K] == -1) {
        int cur = Q.front();
        Q.pop();
        for(int nx : {cur-1,cur+1,2*cur}) { //범위 기반 for문
            if(nx < 0 || nx >= 100002) {
                continue;
            }
            if(dis[nx] >= 0) {
                continue;
            }
            dis[nx] = dis[cur] + 1;
            Q.push(nx);
        }
    }

    cout << dis[K] << '\n';



    return 0;
}