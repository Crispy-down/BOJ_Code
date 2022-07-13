#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int N,M,V; //������ ����,������ ����,Ž�� ������ ���� V
int map[MAX][MAX]; //���� ��� �׷���
bool visited[MAX]; // ���� �湮����
queue<int> q; //BFS => queue,DFS => stack,recursive

void reset() {
    for(int i = 1;i<=N;i++) {
        visited[i] = 0; //�湮�� �迭 �ʱ�ȭ
    }
}

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    for(int i = 1;i<=N;i++) {
        if(map[v][i] == 1 && visited[i] == 0) { //�湮���� ��� + �������ִ�(������� �� 1)
            DFS(i);
        }
    }
}

void BFS(int v) {
    q.push(v);
    visited[v] = true; // v��带 �湮�Ͽ��� = enqueue
    cout << v << " ";

    while(!q.empty()) {
        v = q.front(); //FIFO,�� �������� ���� ���� ������ ť
        q.pop(); //dequeue(�� �� ���� ��� �� enqueue)
        for(int w = 1; w<= N;w++) {
            if(map[v][w] == 1 && visited[w] == 0) {//v�� ������ ��� + �湮���� ��� ���
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
        int a, b; // ���� �������
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