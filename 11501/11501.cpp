#include <bits/stdc++.h>
using namespace std;

int T;
int push;
int N;
vector <int> cost;
long long total = 0;

void pop_and_calculate() {
    int high_cost = cost.back(); // 최고점의 주가를 설정
    cost.pop_back(); // 최고점의 가격은 안들어가니 제외

    if(cost.empty()) {
        return;
    }

    while(!cost.empty()) {
        total += (high_cost - cost.back()); // 최고점의 가격 기준 나머지 애들 주가 계산후 최종 답안에 저장
        cost.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> N;
        cin >> push;
        cost.push_back(push); // 첫날의 주가는 무조건 구매한다 생각

        for(int i = 1;i<N;i++) {
            cin >> push; // 오늘의 주가
            if(push >= cost.back()) { // i-1 = 그 전날의 주가보다 오늘의 주가가 올랐다면?
                cost.push_back(push); // 구매
            }
            else if(push < cost.back()) { // i-1 = 그 전날의 주가보다 오늘의 주가가 내려갔다면?
                pop_and_calculate();
                cost.push_back(push); // 구매
            }      
        }

        if(!cost.empty()) {
            pop_and_calculate();
            cout << total << '\n';
        }
        else {
            cout << total << '\n';
        }

        while(!cost.empty()) {
            cost.pop_back();
        }
        // for문이 끝났는데도 벡터에 남아 있는 경우
        // 주가가 계속 상승 곡선 (마지막날 기준 다 팔아야함)
        // 계속 하락선 (벡터에 하나밖에 없을 것)
        total = 0;
    }
}

// 최고점인 가격을 구해서, 
// 순차 검색을 통해 그 전까지 주가 사놓은거 한번에 다팜
// 문제는, 최고점인 가격 이후 고점인 가격대가 없을 때
// ex) 1 1 3 1 2
// 3 이후, 3이 없음
// 이럴땐 최고점을 다시 구해야하나?