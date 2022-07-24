#include <bits/stdc++.h>
using namespace std;

int N,K;
int dis[100002]; // ���� �Ÿ�
int cnt[100002]; // ���� ��� 

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
            if(dis[nx] >= 0)  { // �湮�ߴ� ���� �湮�� ��
                if(dis[nx] == dis[cur] + 1) { // ���� ĭ�ε� �ٸ� ������� ĭ�� �湮�ϴ� �� = ��� update
                    cnt[nx] += cnt[cur];
                }
            }
            else { // �湮���Ѱ� �湮�� 
                cnt[nx] = cnt[cur]; // �� ĭ���� ���� ����� �� ���� ĭ������ ���� ����� ����
                dis[nx] = dis[cur] + 1; // �Ÿ� update
                Q.push(nx);
            }

        }  
    }

    cout << dis[K] << '\n'; 
    cout << cnt[K];

    return 0;
}