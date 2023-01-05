#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int N;
int min_city_idx;
ll min_city = 1000000001;
ll road_cost[100005];
ll city_cost[100005];
ll total_fuel = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 1;i<N;i++) {
        cin >> road_cost[i]; // i번 도시로 가는 도로 비용
    }
    for(int i = 0;i<N-1;i++) { // i번 도시마다 있는 주유소 리터당 비용
        cin >> city_cost[i];
    }
    cin >> city_cost[N-1];

    for(int i = 1;i<N-1;i++) {
        if(city_cost[i] > city_cost[i-1]) {
            city_cost[i] = city_cost[i-1];
        }
    }

    for(int city = 0; city < N-1; city++) {
        total_fuel += city_cost[city] * road_cost[city+1];
    }

    cout << total_fuel;

}

// N개의 도시가 주어지고, 일직선 도로위에 존재한다.
// 가장 왼쪽 도시 => 오른쪽 도시로 이동하고 싶어함.
// 인접한 두 도시 사이의 도로의 길이가 주어지고, 각 도시마다 1리터당 기름 가격이 주어짐
// 특정 도시당 하나씩 있는 주유소에서 기름을 충전하여 마지막 도시까지 갈 때 최소 비용을 구해라.
// 그렇다면,
// 특정 도시에 도착했을 때, 이용할 수 있는 방법은 두 가지가 있다.
// #1. 주유소를 사용하는 것(끝까지 갈 기름이 없는 경우) - 비용 발생
// #2. 주유소를 사용하지 않는 것 (끝까지 갈 기름이 존재하는 경우) - 비용 발생하지 않음
// 5 2 4 1
//  2 3 1
// 눈앞에 있는것만 충전 할 시:
// 10 + 6 + 4 = 20
// 그렇다면, 비용이 제일 작은 주유소에서 남은 거리만큼 최대한 채우면 되지 않겠는가.
// 비용이 없는 처음에 최소 비용이 아니라면 경우엔 각 거리만큼만 충전한다.
// 최소 비용이 나온 지점에서, 나머지 거리 다 채우면 됨.
// 그 전까지는 다음 거리까지만 채움.

// 도로에 대한 비용 배열
// 도시에 대한 비용 배열 -> 최소 index(최초로 나오는 지점) 찾아서 index + 1 나머지 도로 비용 다 더해서 곱하기.

// 여기까지 내 생각.
// => 더 고쳐야하는 부분은, 
// 뒷 도시의 주유소 리터당 크기가 크다면 앞 도시의 주유소 리터당 크기로 변환하면 된다.
// 주유소 주유 가격이 5 2 4 1 이라면 5 2 2 1 로 고침. 6 2 4 6 8 이라면 6 2 2 2 2 로 고침)