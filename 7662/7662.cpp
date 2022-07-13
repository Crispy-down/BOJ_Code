#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T,N;
    cin >> T;
    char command;
    int value;
    bool visited[1000001];

    for(int t = 0;t<T;t++) {
        cin >> N;

        priority_queue<pair<int,int>> pq; //max heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pQ; //min heap

        for(int i = 0;i<N;i++) {
            cin >> command >> value;

            if(command == 'I') {
                pq.push({value,i}); // val , i
                pQ.push({value,i});
                visited[i] = true;
            }
            else if(command == 'D') {
                if(value == -1) { // minimum val pop
                    while(!pQ.empty() && !visited[pQ.top().second]) {
                        pQ.pop();
                    }
                    if(!pQ.empty()) { 
                        visited[pQ.top().second] = false;
                        pQ.pop();
                    }
                }
                else if(value == 1) { // maximum val pop
                    while(!pq.empty() && !visited[pq.top().second]) {
                        pq.pop();
                    }
                    if(!pq.empty()) {
                        visited[pq.top().second] = false;
                        pq.pop();
                    }
                }
            }
        }

        while(!pQ.empty() && !visited[pQ.top().second]) {
            pQ.pop();
        }
        while(!pq.empty() && !visited[pq.top().second]) {
            pq.pop();
        }

        if(pq.empty() && pQ.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            cout << pq.top().first << " " << pQ.top().first << '\n';
        }
    }
    return 0;
}