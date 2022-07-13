#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int **arr = new int*[N];
    for(int i = 0;i<N;i++) {
        arr[i] = new int[3];
    }

    for(int i = 0;i<N;i++) {
        for(int k = 0;k<3;k++) {
            cin >> arr[i][k];
        }
    }

    for(int i = 1;i<N;i++) {
        for(int k = 0;k<3;k++) {
            if(k == 0) {
                arr[i][k] = arr[i][0] + min(arr[i-1][1],arr[i-1][2]);
            }
            else if(k == 1) {
                arr[i][k] = arr[i][1] + min(arr[i-1][0],arr[i-1][2]);
            }
            else {  
                arr[i][k] = arr[i][2] + min(arr[i-1][1],arr[i-1][0]);
            }
        }
    }

    cout << min({ arr[N-1][0],arr[N-1][1],arr[N-1][2] });

    for(int i = 0;i<N;i++) {
        delete [] arr[i];
    }
    delete [] arr;


    return 0;
}