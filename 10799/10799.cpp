#include <iostream>
#include <stack>

using namespace std;

string input;
stack <char> c;
int result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;

    for(int i = 0;i<input.length();i++) {
        if(input[i] == '(') {
            c.push(input[i]);
        }
        else if(input[i] == ')') {
            if(input[i-1] == '(') {
                c.pop();
                result += c.size();
            }
            else {
                c.pop();
                result += 1;
            }
        }
    }

    cout << result;


    return 0;
}
//풀이 참고함
// 레이저 이전 여는 괄호의 개수만큼 더하면 됨
// 이는 레이저가 나누는 왼쪽 방면의 막대 개수를 더한것.
// () 이때의 닫는 괄호 만날때는 스택의 개수만큼
// ) 그냥 닫는 괄호는 닫힘에 의해 늘어나는 막대의 개수 + 1