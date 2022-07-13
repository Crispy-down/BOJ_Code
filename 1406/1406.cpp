#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

string input; // input string
string result; // result string
int T; // cmd count

stack <char> cursor; // 받은 문자열 스택으로 저장.
vector <char> cursor_data; // cursor에서 pop한 데이터 push_back


void cursor_left() { // L 커서를 왼쪽으로 한칸 옮김
    char temp;
    if(cursor.empty()) { // 커서가 문장의 맨 앞이면 무시(스택이 비었을때 무시)
        return;
    }
    temp = cursor.top(); // 스택의 맨 위 값 (커서 이동)
    cursor.pop(); // 왼쪽 커서 이동
    cursor_data.push_back(temp); //데이터 값 따로 저장
}

void cursor_right() { // D 커서를 오른쪽으로 한칸 옮김
    char temp;
    if(cursor_data.empty()) { // cursor에서 pop한 데이터가 없음 = 스택이 꽉찬 상태 = 문장의 맨 뒤
        return;
    }
    temp = cursor_data.back(); // 저장된 데이터 맨 뒤의 원소
    cursor_data.pop_back(); // 삭제
    cursor.push(temp); // 커서 오른쪽 이동
}

void delete_left() { // B 커서 왼쪽에 있는 문자를 삭제함
    if(cursor.empty()) { // 커서가 문장 맨 앞이면 무시
        return;
    }
    cursor.pop();
}

void insert_word(char w) { // P $  / $ 문자 왼쪽에 추가.
    cursor.push(w);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    for(int i = 0;i<input.length();i++) {
        cursor.push(input[i]);
    }

    cin >> T;
    cin.ignore();

    string cmd; // command

    for(int i = 0;i<T;i++) {
        getline(cin,cmd);
        if(cmd == "L") {
            cursor_left();
        }
        else if(cmd == "D") {
            cursor_right();
        }
        else if(cmd == "B") {
            delete_left();
        }
        else {
            insert_word(cmd[2]);
        }
    }

    for(int k = cursor_data.size()-1;k >= 0;k--) {
        cursor.push(cursor_data[k]); // 저장된 데이터를 거꾸로 넣어야함(스택이라)
    }

    while(!cursor.empty()) {
        result += cursor.top();
        cursor.pop();
    }

    reverse(result.begin(),result.end());

    cout << result;

    return 0;
}