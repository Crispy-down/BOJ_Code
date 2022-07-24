#include <bits/stdc++.h>
using namespace std;

int N,K;
int dis[100002]; // 가는 거리
int cnt[100002]; // 가는 방법 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    fill(&dis[0],&dis[100001],-1); // initialize

    queue <int> Q;
    Q.push(N);
    dis[N] = 0;
    cnt[N] = 1;

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(int nx : {cur + 1,cur -1,cur*2}) {
            if(nx < 0 || nx >= 100002) {
                continue;
            }
            if(dis[nx] >= 0)  { // 방문했던 곳을 방문할 때
                if(dis[nx] == dis[cur] + 1) { // 같은 칸인데 다른 방법으로 칸에 방문하는 것 = 방법 update
                    cnt[nx] += cnt[cur];
                }
            }
            else { // 방문안한곳 방문시 
                cnt[nx] = cnt[cur]; // 그 칸으로 가는 방법은 그 전의 칸까지의 가는 방법과 같음
                dis[nx] = dis[cur] + 1; // 거리 update
                Q.push(nx);
            }

        }  
    }

    cout << dis[K] << '\n'; 
    cout << cnt[K];

    return 0;
}