#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <char> c;
stack <string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "";
    string result = "";

    getline(cin,str);

    bool flag = true;

    for(int i = 0;i<str.length();i++) {
        if(str[i] == '<') {
            flag = false;
        }
        else if(str[i] == '>') {
            flag = true;
        }
        else if(flag) {
            c.push(str[i]);
            if(i < str.length()-1) {
                if(str[i+1] == '<') {
                    c.push(' ');
                }
            }
        }
    } // except for tag push all word into stack(char)

    if(!c.empty() && c.top() == ' ') { //empty => segfault
        c.pop();
    }

    while(!c.empty()) {
        result += c.top();
        c.pop();
    }

    int pos = 0;
    string temp = "";

    for(int i = 0;i<result.length();i++) {
        if(result[i] == ' ') {
            temp = result.substr(pos,i-pos);
            s.push(temp);
            pos = i+1;
        }
    }

    s.push(result.substr(pos)); // ���ڿ� �Ųٷ��� ���ڵ� ������.

    pos = 0;
    flag = true;

    while(true) {
        //������ ���ڿ��߿��� �±� ����,���� ������ �� ���� ���̸�ŭ replace
        //������ ������ �� ���� ���� �� ��ĭ �� replace
        if(pos >= str.length()) {
            break;
        }
        if(str[pos] == '<') {
            flag = false;
        }
        else if(str[pos] == '>') {
            flag = true;
        }
        else if(flag && str[pos] != ' ') {
            if(!s.empty()) {
                temp = s.top();
                str.replace(pos,temp.length(),temp);
                s.pop();
                pos += temp.length()-1;
            }
        }
        pos++;
    }

    cout << str;

    return 0;
}