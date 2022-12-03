#include <bits/stdc++.h>
using namespace std;

int N;
int H;
stack <pair<int,int>> S;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1;i<=N;i++) {
        cin >> H; // 높이 입력
        while(!S.empty()) { // 스택이 비어있지 않다면
            if(S.top().second > H) { // 최상위 탑 값의 높이가 입력받은 높이보다 크다
                cout << S.top().first << ' '; // 그럼 거기서 수신함
                break;
            }
            S.pop(); // top의 높이가 크지 않다면 항목 pop(다른곳에서 수신함)
            // 애초에 높이가 크지않다는거는 비교할 필요가 없다는것, 따라서 항목 제외
        }

        if(S.empty()) { // 초기값이나 비어있다면 비교할게 없음 => 수신 x
            cout << "0 ";
        }

        S.push({i,H}); // 타워 인덱스와 높이를 집어넣음
    }

    return 0;
}