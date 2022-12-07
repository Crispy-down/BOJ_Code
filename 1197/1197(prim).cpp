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

    // tuple <int,int,int> => ���, ���� 1 , ���� 2
    priority_queue< tuple <int,int,int>,
                    vector<tuple<int,int,int>>,
                    cmp > pq;

    int cnt = 0; // ���õ� ������ ��
    int ans = 0; // ����ġ ��
    
    chk[1] = 1; // 1�� ���� �湮
    for(auto nxt : adj[1]) { // 1�� ������ ������ ��� ���� �켱���� ť ����
        pq.push({nxt.first, 1 , nxt.second}); // cost, 1 , to v2
    }


    while(cnt < V -1) {
        int cost,a,b;
        tie(cost,a,b) = pq.top();
        pq.pop();
        if(chk[b]) { // ������ ������ �湮���� ����� ����(v2)
            continue;
        }
        ans += cost;
        chk[b] = 1; // -> b ���� ����
        cnt++;
        for(auto nxt : adj[b]) { // ������ b ������ ������ ������ �湮���� ��带 pq�� �߰�
            if(!chk[nxt.second]) { // v2 �湮 ������ ��
                pq.push({nxt.first,b,nxt.second});
            }
        }
    }

    cout << ans;



    return 0;
}