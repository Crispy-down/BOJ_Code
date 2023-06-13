#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> adj[10005];
int deg[10005];
int time1[10005];

int N;
int result[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int t, a, b;

    for (int i = 1; i <= N; i++)
    {
        cin >> t;
        time1[i] = t;
        cin >> a;
        for (int k = 0; k < a; k++)
        {
            cin >> b;
            adj[b].push_back(i);
            deg[i]++;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
        result[i] = time1[i];
    }

    int tmp = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur])
        {
            deg[nxt]--;
            result[nxt] = max(result[nxt], result[cur] + time1[nxt]);
            // time update => (기존 작업의 시간 vs 현재 인접한 노드의 작업시간 합) 최대값
            if (deg[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }

    int ans = -1;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, result[i]);
    }
    cout << ans;

    return 0;
}