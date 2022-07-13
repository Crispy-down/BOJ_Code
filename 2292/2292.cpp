#include <iostream>

using namespace std;

int main() {
    int N;
    int M = 1;
    int cnt = 1;
    cin >> N;
    while(N>M) {
        if(N == 1) {
            break; 
        }
        M += 6*cnt;
        cnt += 1;
    }
    cout << cnt;
    return 0;
}