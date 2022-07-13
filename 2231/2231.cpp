#include <iostream>

using namespace std;

int main() {
    int N ,sum,answer = 0;
    int count = 0;
    int digit = 0;
    cin >> N;
    while(N > 0) {
        N /= 10;
        digit++;
    }
    for(int i = N;i> N - digit*9;i--) {
        if(i + i%10 + (i %100 - i%10) + ((i-i%100)/100) == N) {
            count++;
            answer = i;
            break;
        }
    }

    if(count == 0) {
        cout << 0;
    }
    else {
        cout << answer;
    }
 


    return 0;
}