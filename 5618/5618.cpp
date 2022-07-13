#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector <int> v;
    
    int *arr = new int[N];

    for(int i = 0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr,arr+N);

    int temp = 1;

    if(N == 2) {
        while(temp <= arr[1]) {
            if(arr[0]%temp == 0 && arr[1]%temp == 0) {
                v.push_back(temp);
            } 
            temp++;
        }
    }
    else {
        while(temp <= arr[2]) {
            if(arr[0]%temp == 0 && arr[1]%temp == 0 && arr[2]%temp == 0) {
                v.push_back(temp);
            }
            temp++;
        }
    }

    for(int i = 0;i<v.size();i++) {
        cout << v[i] << '\n';
    }

    delete[] arr;
    return 0;
}