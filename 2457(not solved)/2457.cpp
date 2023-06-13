#include <bits/stdc++.h>
using namespace std;

int N;
int start_M,start_D,finish_M,finish_D;
int ans;
tuple <int,int,int,int> flower[100005];

bool cmp(tuple <int,int,int,int> a, tuple <int,int,int,int> b) {
    if(get<0>(a) == get<0>(b)) {
        if(get<1>(a) == get<1>(b)) {
            if(get<2>(a) == get<2>(b)) {
                return get<3>(a) < get<3>(b);
            }
            return get<2>(a) < get<2>(b);
        }
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0;i<N;i++) {
        cin >> start_M >> start_D >> finish_M >> finish_D;
        flower[i] = {start_M,start_D,finish_M,finish_D};
    }

    sort(flower,flower + N,cmp);

    if(get<0>(flower[0]) >= 3 && get<1>(flower[0]) >= 2) {
        cout << 0;
        return 0;
    }



    // for(int i = 0;i<N;i++) {
    //     cout << get<0>(flower[i]) << " "  << get<1>(flower[i]) << " "  << get<2>(flower[i]) << " " <<  get<3>(flower[i]) << "\n";    
    // }






}
// 늘 꽃이 펴있는 정원을 만들고 싶다.
// N개의 꽃이 존재.
// 꽃은 모두 같은 해에 피어서 같은 해에 진다.
// 하나의 꽃은 피는 날과 지는 날이 정해져 있다.
// ex) 
// 5월 8일 개화 -> 6월 13일 짐
// 6월 13일부터 이후로는 꽃을 볼 수 없다.
// 4 6 9 11월은 30일까지.
// 1 3 5 7 8 10 12얼은 31일까지.
// 2월은 28일까지.
// N개의 꽃들 중 2가지 조건을 만족하는 꽃을 선택하고 싶다.
// #1. 공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어있도록 한다.
// #2. 정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게한다.
// N개의 꽃들 중, 위 두 조건을 만족하는 꽃을 선택할 때, 선택한 꽃들의 최소 개수를 출력해라.

// 하나의 꽃을 선택 했을 때, 꽃이 지는 시점을 기준으로
// 그 이전의 꽃들 중 가장 길게 피는 꽃을 고른다.(종료시점 기준)
// 종료 시점이 12월 1일이면 됨.
// 개화 시점은 최소 3월 1일.
// 3월 1일부터 11월 30일까지 하나라도 안 피면 안됨.
// 최소의 개수로 심어야하기 때문에, 각자 꽃이 가지는 시간대의 겹치는 시간이 최대화가 되어야 꽃의 개수가 줄겠지.

// 우선, 정렬해야함 (tuple)
// 개화 시기 월 오름차순, 같다면 일 비교.
// 3월 전 하나 꽃 선택, 이는 지는 시기가 가장 긴것을 골라야함.
// 그 다음, 지는 시기 기준 그 이전의 꽃들 중, 