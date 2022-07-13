#include <iostream>
using namespace std;

string answer = "I love UCPC";
string wrong = "I hate UCPC";
string case_answer = "UCPC";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    string temp; // puts all uppercase single word

    getline(cin,str);

    for(int i = 0;i<str.length();i++) {
        if(str[i] >= 65 && str[i] <= 90) {
            temp += str[i]; // 대문자만 뽑아냄
        }
    }

    int cnt = 0;

    if(temp.length() > 0) {
        for(int i = 0;i<temp.length();i++) {
            if(temp[i] == case_answer[cnt]) {
                cnt++;
                if(cnt > 3) {
                    break;
                }
            }
        }
        if(cnt == 4) {
            cout << answer;
        }
        else {
            cout << wrong;
        }
    }
    else {
        cout << wrong;
    }

    return 0;
}
// 대문자끼리 뽑아내서 그 문자열 자체중에서
// U C P C 가 존재하는지 다시 확인해야하는 문제.
// 포인터 두개를 사용하여,
// 해당 대문자가 순서대로 존재하면 count up을 통해서 판단함
// 대문자만 뽑아내면 되는줄 알고 틀림 ㅋㅋ