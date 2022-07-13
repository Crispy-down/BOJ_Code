#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[1000] = {0};
    cin >> n;
    arr[0] = 1;
    arr[1] = 3;
    for(int i=2;i<1000;i++) {
        arr[i] = (arr[i-1] + (arr[i-2] * 2)) % 10007;
    }
    cout << arr[n-1];
    return 0;
}