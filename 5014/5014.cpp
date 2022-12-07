#include <bits/stdc++.h>
using namespace std;

int F,S,G,U,D;
int dist[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> F >> S >> G >> U >> D;

    for(int i = 1;i<=F;i++) {
        dist[i] = -1; // FILL
    }

    queue <int> Q;
    dist[S] = 0;
    Q.push(S);

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(int nx : {cur + U , cur - D}) {
            if(nx < 1 || nx > F) {
                continue;
            }
            if(dist[nx] >= 0) {
                continue;
            }
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    if(dist[G] >= 0) {
        cout << dist[G];
    }
    else {  
        cout << "use the stairs";
    }
}