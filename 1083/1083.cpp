#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,s;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0;i<n;i++) {
        cin >> arr[i];
    }
    cin >> s;

    for(int i = 0;i<n;i++) { // 사전순 가장 낮은 순서 == 가장 큰값이 배열 첫번째로 오게하기
        int max = arr[i]; 
        int maxi = i;
        for(int j = i+1;j<n;j++) {
            if(s-(j-i) >= 0) {
                if(max < arr[j]) {
                    max = arr[j];
                    maxi = j;
                }
            }
        }
        for(int j = maxi;j>i;j--) {
            swap(arr[j],arr[j-1]); //최대값을 옮길수 있는 횟수 내에서 가져오고 나머지 데이터 밀어내기
        }
        s -= (maxi - i); // 옮긴 횟수 갱신
        if(s <= 0) {
            break;
        }
    }

    for(int i = 0;i<n;i++) {
        cout << arr[i] << " ";
    } // answer
    delete[] arr;
}