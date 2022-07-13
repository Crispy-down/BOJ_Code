#include <iostream>

using namespace std;

int main() {
    int N;
    int tmp;
    int arr[11] = {0};
    cin >> N;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    for(int i = 3;i<11;i++) {
        arr[i] = arr[i-2] + arr[i-1] + arr[i-3];
    }
    for(int i = 0;i<N;i++) {
        cin >> tmp;
        cout << arr[tmp-1] << '\n';
    }
    return 0;
}