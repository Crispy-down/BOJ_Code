#include <bits/stdc++.h>
using namespace std;

int N;
int ban_cnt;
int ban;
bool ban_num[10];
string check_num;
bool flag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0;i<10;i++) {
        ban_num[i] = true;
    }

    cin >> N;
    cin >> ban_cnt;

    for(int i = 0;i<ban_cnt;i++) {
        cin >> ban;
        ban_num[ban] = false;
    }

    int ans = abs(N - 100);

    for(int pos = 0;pos<=1000000;pos++) {
        flag = true;

        check_num = to_string(pos); // 검사를 위해 string 변환

        for(int i = 0;i<check_num.size();i++) { // 한자리수씩 체크 (스트링 활용 / 한자리수 모듈러 연산)
            if(!ban_num[check_num[i]-'0']) { // 고장난버튼이 있다면 넘어감 pos
                flag = false;
                break;
            }
        }

        if(flag) { // 고장난 버튼이 없음 => 이동
            if(ans > check_num.size() + abs(N - pos)) { // 최솟갑 갱신
                ans = check_num.size() + abs(N - pos);
            }
        }
    }

    cout << ans;

}

// 원래 내 풀이 방식 :
// 상한값과 하한값 두개를 직접 구해서 절댓값 차이 + 자릿수  (2개)
// 100번에서 절댓값 차이 (1개)
// 총 3개의 최솟값 비교
// => 80000 8 9 일때 77777이 상한-하한값인데 코딩이 잘못됨.(기능 구현 문제)

// 풀이 참고 :( BRUTE FORCE )
// #1. 0 ~ 백만(or N x 2까지 범위중 완전 탐색 => N 최대 범위가 500000인데, 1 ~ 5까지 고장났다면 0부터 499999번 하는거 보다 666666에서 -하는 연산이 더 적음)
// #2. 해당 숫자에 대해 각 자리수 고장났는지 안났는지 체크
// #3. 안고장났다면 그 채널로 이동
// #4. 자릿수 + N - pos 절댓값이 정답 후보
// #5. solution set 중 최솟값 출력.

// 풀이방향을 앞으로  직접 다 구하려고하지 말고, '완전 탐색' 문제인 만큼 하드코딩보다 틀을 깨자.