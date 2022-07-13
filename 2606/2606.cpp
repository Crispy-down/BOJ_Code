#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

int N,M,V;
int map[MAX][MAX];
bool visited[MAX];
queue<int> q;


void reset() {
    for(int i = 1;i<=N;i++) {
        visited[i] = 0;
    }
}

void BFS(int v) {
    q.push(v);
    visited[v] = true;
    while(!q.empty()) {
        v = q.front();
        q.pop();
        for(int w = 1; w<= N;w++) {
            if(map[v][w] == 1 && visited[w] == 0) {
                q.push(w);
                visited[w] = true;
            }
        }
    }   
}


int main() {
    cin >> N;
    cin >> M;
    for(int i = 0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    reset();
    BFS(1);

    int count = 0;
    for(int i = 1;i<=N;i++) {
        if(visited[i] == true) {
            count += 1;
        }
    }
    cout << count-1 << endl;
}