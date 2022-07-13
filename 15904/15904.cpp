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
            temp += str[i]; // �빮�ڸ� �̾Ƴ�
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
// �빮�ڳ��� �̾Ƴ��� �� ���ڿ� ��ü�߿���
// U C P C �� �����ϴ��� �ٽ� Ȯ���ؾ��ϴ� ����.
// ������ �ΰ��� ����Ͽ�,
// �ش� �빮�ڰ� ������� �����ϸ� count up�� ���ؼ� �Ǵ���
// �빮�ڸ� �̾Ƴ��� �Ǵ��� �˰� Ʋ�� ����