#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue <int> q;
vector <int> v;
int N,K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int temp;

    for(int i = 1;i<N+1;i++) {
        q.push(i);
    }

    for(int i = 0;i<N;i++) {
        for(int k = 0;k<K;k++) {
            temp = q.front();
            q.pop();
            if(k == K-1) {
                v.push_back(temp);
                continue;
            }
            q.push(temp);
        }
    }
    cout << "<";
    for(int i = 0;i<v.size();i++) {
        if(i == v.size()-1) {
            cout << v[i];
            break;
        }
        cout << v[i] << ", ";
    }
    cout << ">";

    return 0;
}