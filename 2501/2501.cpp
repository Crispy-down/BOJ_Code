#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;

    vector <int> v;

    int temp = 1;

    while(temp <= N) {
        if(N % temp == 0) {
            v.push_back(temp);
        }
        temp++;
    }

    if(K > v.size()) {
        cout << 0;
    }
    else {
        cout << v[K-1]; 
    }


    return 0;
}