#include <iostream>
#include <string>
using namespace std;

int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    string num;


    for(int i = 1;i<1000001;i++) {
        num = to_string(i);
        for(int k = 0;k<num.length();k++) {
            if(num[k] -'0' == 3 || num[k] - '0' == 6 || num[k] - '0' == 9) {
                cnt++;
            }
        }
        arr[i] = cnt;
    }


    cout << arr[N];

    return 0;
}