#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> v;
int arr[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(N>0){
        v.push_back(N%10);
        N /= 10;
    }

    for(int i = 0;i<v.size();i++) {
        arr[v[i]]++;
    }

    int div = (arr[6] + arr[9] + 1) / 2;
    arr[6] = div;
    arr[9] = div;

    cout << *max_element(arr,arr+10);

    return 0;
}

// N 받고 10으로 모듈러 연산 후 0이 될때 까지 10으로 나눔
// 벡터에 한자리 수 다 저장
// 정렬
// 1 ~ 9 중복해서 값 저장되어있음
// 최대 7개
// 6,9 제외 값들 중복되어있을 때 +1
// 6 9는 공유 가능.
// ex) 9 9 9 9 -> 6 대체 가능, 세트 2개.
// int arr[n] ++ (일렬 탐색)
// 6이나 9가 나오면 