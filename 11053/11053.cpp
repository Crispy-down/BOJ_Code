//배열에서 최솟값을 찾은 후
//그 인덱스부터 값들을 비교하며 증가하는 부분수열을 구해야할거 같음
//근데 배열을 다 접근하면 O(N)일거같은데 
// 
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int *arr = new int[N];

    for(int i = 0;i<N;i++) {
        cin >> arr[i];
    }










    delete[] arr;
    return 0;
}