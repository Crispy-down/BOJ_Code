#include <iostream>

using namespace std;

int main() {
    int N;
    int arr[1000] = {0};
    cin >> N;
    arr[0] = 1;
    arr[1] = 2;
    for(int i=2;i<1001;i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % 10007; // (a mod n + b mod n)mod n = (a+b)mod n
    }
    cout << arr[N-1] << '\n';
    return 0;
}