#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> pri;

    string answer = "";
    string input;
    char temp;
    cin >> input;

    for(int i = 0;i<input.size();i++) {
        if(input[i] == '+' || input[i] == '-') {
            if(!pri.empty()) {
                if(pri.top() == '*' || pri.top() == '/') { // ALL POP
                    while(!pri.empty()) {
                        temp = pri.top();
                        if(temp == '(') { // when met the open => stop
                            break;
                        }
                        answer += temp;
                        pri.pop();
                    }
                }
                else if(pri.top() == '-' || pri.top() == '+') { // one pop
                        temp = pri.top();
                        answer += temp;
                        pri.pop();
                    }
            }
            pri.push(input[i]);
        }
        else if(input[i] == '*' || input[i] == '/') { 
            if(!pri.empty()) {
                if(pri.top() == '*' || pri.top() == '/') {
                    while(!pri.empty()) {
                        temp = pri.top();
                        if(temp == '+' || temp == '-' || temp == '(') { // when met the open or lower priority => stop
                            break;
                        }
                        answer += temp;
                        pri.pop();
                    }
                }
            }
            pri.push(input[i]);
        }
        else if(input[i] == '(') { 
            pri.push('(');
        }
        else if(input[i] == ')') {
            while(!pri.empty()) {
                temp = pri.top();
                if(temp == '(') { // first met open => pop and break;
                    pri.pop();
                    break;
                }
                answer += temp;
                pri.pop();
            }
        }
        else { // Upper Case
            answer += input[i];
        }
    }
    while(!pri.empty()) {
        temp = pri.top();
        answer += temp;
        pri.pop();
    } 
    cout << answer;
}