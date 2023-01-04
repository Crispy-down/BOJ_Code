#include <bits/stdc++.h>
using namespace std;

int N;
int max_w = -1;
int num[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0;i<N;i++) {
        cin >> num[i];
    }

    sort(num,num + N);

    for(int pos = 0;pos<N;pos++) { // 로프 하나씩 선택했다고 생각
        if(max_w < num[pos] * (N-pos)) { // 해당 로프의 최대 중량만큼 들 수 있으니, * 남은 로프 수 곱하기 
        //= 해당 로프를 쓸 때 나올 수 있는 최대 중량
            max_w = num[pos] * (N-pos);
        }    
    }

    cout << max_w;
}

// 로프를 병렬로 연결했을 때 상황을 생각해보면,
// 크기가 제일 작은 놈부터 하나씩 선택했을 때
// 그 크기 이상으로 들지 못함. 
// 따라서 그 뒤 남은 로프 개수 만큼 곱한 것 중 최댓값을 뽑아내면 되는 문제
// * 로프 하나를 선택 했을 때, 
// * 해당 로프 최대중량만큼 들 수 있으니 남은 로프 개수만큼 곱하면 최대 중량이 나온다