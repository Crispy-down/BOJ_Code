#include <bits/stdc++.h>
using namespace std;

int n,m;
int parent[1000005];

int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int x,int y) {
    x = find(x);
    y = find(y);
    if(x == y) {
        return;
    }
    parent[y] = x;
}

string isunion(int x,int y) {
    x = find(x);
    y = find(y);
    if(x == y) {
        return "YES";
    }
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cmd;
    int a,b;

    for(int i = 1;i<1000001;i++) {
        parent[i] = i;
    }

    cin >> n >> m;

    while(m--) {
        cin >> cmd >> a >> b;
        if(cmd == 0) { // merge
            merge(a,b);
        }
        else { // isunion
            cout << isunion(a,b) << '\n';
        }

    }

    return 0;
}