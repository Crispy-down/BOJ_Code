#include <iostream>
#include <stack>

using namespace std;

int N;
int F[1000001];
int input[1000001];
stack <int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0;i<N;i++) {
        cin >> input[i];
        F[input[i]]++;
    }

    int temp;

    for(int i = 0;i<N;i++) {
        if(s.empty()) { // 스택이 비어있다면 idx 삽입
            s.push(i);
        }
        else { // 스택에 값이 있는 경우
            for(int k = 0;k<N;k++) { // N번
                if(s.empty()) { // 스택이 비었을 경우 push하고 break;
                    s.push(i);
                    break;
                }
                temp = s.top(); // idx
                if(F[input[i]] > F[input[temp]]) { // F값 비교 => 스택에 있는 최상위 idx값의 입력값에 대한 F 값 / 현재 입력 idx에 대한 F값
                    input[temp] = input[i]; // 오등큰수 대입
                    s.pop(); 
                }
                else {
                    s.push(i); // 값이 같거나 작다면 그냥 push(내림차순 유지)
                    break;
                }
            }
        }
    }

    while(!s.empty()) { // N번 반복 후 남아있는 요소들은 전부 오등큰수가 없음
        temp = s.top();
        input[temp] = -1;
        s.pop();
    }

    for(int i = 0;i<N-1;i++) {
        cout << input[i] << " ";
    }
    cout << input[N-1];

    return 0;
}