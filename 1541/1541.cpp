#include <iostream>
#include <string>
using namespace std;

int main() {
    //연속해서 두개 이상의 연산자가 나타나지 않는다 == + -가 번갈아가면서 나온다.
    // 그렇다면,- 뒤 + 기호는 -로, +는 그냥 +하면 최소값이 나온다.(괄호로 묶기)
    string str;
    cin >> str;
    int result = 0;
    string num;
    bool isMinus = false; // 앞 연산자가 - 인가?
    for(int i = 0;i<= str.size();i++) {
        if(str[i] == '-' || str[i] == '+' || i == str.size()) {
            if(isMinus) { //앞 연산자가 -였다면 +연산이라도 빼야함
                result -= stoi(num);
                num = "";
            }
            else { // 앞 연산자가 +
                result += stoi(num);
                num = "";
            }
        }
        else { //연산자를 만나기 전까지 계속 숫자를 문자열로 붙임
            num += str[i];
        }
        if(str[i] == '-') {
            isMinus = true; // - 연산자 뒤는 + 연산자가 오지만 최소값을 위해 괄호로 묶기 = -연산
        }
    }
    cout << result;
}