#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int v,e,st; // 정점의 개수, 간선의 개수 , 시작정점

// {비용, 정점번호}
vector <pair<int,int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005]; // 최단거리 테이블

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e >> st;
    fill(d,d+v+1,INF);
    while(e--) {
        int u,v,w;
        cin >> u >> v >> w; // u -> v cost : w
        adj[u].push_back({w,v});
    }

    priority_queue<pair<int,int> , vector<pair<int,int>>, greater <pair<int,int>> > pq; // min heap
    d[st] = 0; 
    pq.push({d[st],st}); // 우선순위 큐에 (0,시작점) 추가
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop(); // {비용,정점번호}
        if(d[cur.Y] != cur.X) {
            continue; // 거리가 최단거리 테이블에 있는 값과 다를경우 넘어감(최단경로 이미 삽입됨)
            }
        for(auto nxt : adj[cur.Y]) { 
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) {
                continue;
            }
            d[nxt.Y] = d[cur.Y] + nxt.X; 
            pq.push({d[nxt.Y], nxt.Y});
            // cur를 거쳐가는 것이 더 작은 값을 가질 경우
            // d[nxt.Y]을 갱신하고 우선순위 큐에 (거리, nxt.Y) 추가
        }
    }

    for(int i = 1;i<=v;i++) {
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}