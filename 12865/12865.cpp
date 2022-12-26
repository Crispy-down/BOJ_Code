#include <bits/stdc++.h>
using namespace std;

int N,K;
int W,V;
int dp[102][100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector <int,int> item;

    cin >> N >> K;
    while(N--) {
        cin >> W >> V; // weight , cost
        item.push_back({W,V});
    }


}