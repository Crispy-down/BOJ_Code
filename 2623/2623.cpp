#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int> adj[1005];
int deg[1005];

queue<int> q;
vector<int> result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    int c;

    while (M--)
    {
        cin >> c;
        int a, b;
        cin >> a;
        for (int i = 1; i < c; i++)
        {
            b = a;
            cin >> a;
            adj[b].push_back(a);
            deg[a]++;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (int nxt : adj[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }

    if (result.size() != N)
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << '\n';
        }
    }
}