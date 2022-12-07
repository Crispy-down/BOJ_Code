#include <bits/stdc++.h>
using namespace std;

int T,N;
int arr[1002];
int vis[1002];

void reset() {
    for(int i = 1;i<=N;i++) {
        arr[i] = 0;
        vis[i] = -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int a = 0;a<T;a++) {
        cin >> N;
        int cycle_cnt = 0;
        reset();
        for(int i = 1;i<=N;i++) {
            cin >> arr[i];
        }
        queue <int> Q;
        for(int i = 1;i<=N;i++) {
            if(vis[i] != -1) {
                Q.push(i);
                vis[i] = 1;
                cycle_cnt++;
                while(!Q.empty()) {
                    int cur = Q.front();
                    Q.pop();
                    if(vis[cur] != -1) {
                        continue;
                    }
                    vis[cur] = 1;
                    Q.push(cur);
                }
            }
        }
        cout << cycle_cnt;
    }













    return 0;
}