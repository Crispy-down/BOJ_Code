#include <bits/stdc++.h>
using namespace std;

int V,E;
vector <pair<int,int>> adj[10005];
bool chk[10005];

struct cmp {
    int operator()(const tuple <int,int,int>& a, const tuple <int,int,int>& b) {
        return get<0>(a) >= get<0>(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    while(E--) {
        int from,to,cost;
        cin >> from >> to >> cost;
        adj[from].push_back({cost,to});
        adj[to].push_back({cost,from});
    }

    // tuple <int,int,int> => 비용, 정점 1 , 정점 2
    priority_queue< tuple <int,int,int>,
                    vector<tuple<int,int,int>>,
                    cmp > pq;

    int cnt = 0; // 선택된 간선의 수
    int ans = 0; // 가중치 합
    
    chk[1] = 1; // 1번 정점 방문
    for(auto nxt : adj[1]) { // 1번 정점에 인접한 노드 전부 우선순위 큐 삽입
        pq.push({nxt.first, 1 , nxt.second}); // cost, 1 , to v2
    }


    while(cnt < V -1) {
        int cost,a,b;
        tie(cost,a,b) = pq.top();
        pq.pop();
        if(chk[b]) { // 선택한 간선중 방문을한 노드라면 제외(v2)
            continue;
        }
        ans += cost;
        chk[b] = 1; // -> b 간선 선택
        cnt++;
        for(auto nxt : adj[b]) { // 선택한 b 간선에 인접한 간선중 방문안한 노드를 pq에 추가
            if(!chk[nxt.second]) { // v2 방문 안했을 때
                pq.push({nxt.first,b,nxt.second});
            }
        }
    }

    cout << ans;



    return 0;
}