#include <iostream>

using namespace std;

int main() {
    int L,P,tmp;
    int arr[5] = {0};
    cin >> L >> P;
    for(int i = 0;i<5;i++) {
        cin >> tmp;
        arr[i] = tmp - (L*P);
    }
    for(int j = 0;j<5;j++) {
        cout << arr[j] << ' ';
    }

    return 0;

}