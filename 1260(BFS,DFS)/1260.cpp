#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int N,M,V; //정점의 개수,간선의 개수,탐색 시작할 정점 V
int map[MAX][MAX]; //인접 행렬 그래프
bool visited[MAX]; // 정점 방문여부
queue<int> q; //BFS => queue,DFS => stack,recursive

void reset() {
    for(int i = 1;i<=N;i++) {
        visited[i] = 0; //방문한 배열 초기화
    }
}

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    for(int i = 1;i<=N;i++) {
        if(map[v][i] == 1 && visited[i] == 0) { //방문안한 노드 + 인접해있다(인접행렬 값 1)
            DFS(i);
        }
    }
}

void BFS(int v) {
    q.push(v);
    visited[v] = true; // v노드를 방문하였음 = enqueue
    cout << v << " ";

    while(!q.empty()) {
        v = q.front(); //FIFO,맨 먼저들어온 값이 먼저 나가는 큐
        q.pop(); //dequeue(한 뒤 인접 노드 다 enqueue)
        for(int w = 1; w<= N;w++) {
            if(map[v][w] == 1 && visited[w] == 0) {//v에 인접한 노드 + 방문안한 노드 대상
                q.push(w);
                visited[w] = true;
                cout << w << " ";
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;
    for(int i = 0;i < M;i++) {
        int a, b; // 간선 연결관계
        cin >> a >> b;
        map[a][b] = 1; //undirected graph(reflective)
        map[b][a] = 1;
    }

    reset();
    DFS(V);

    cout << '\n';

    reset();
    BFS(V);

    return 0;
}