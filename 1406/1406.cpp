#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

string input; // input string
string result; // result string
int T; // cmd count

stack <char> cursor; // ���� ���ڿ� �������� ����.
vector <char> cursor_data; // cursor���� pop�� ������ push_back


void cursor_left() { // L Ŀ���� �������� ��ĭ �ű�
    char temp;
    if(cursor.empty()) { // Ŀ���� ������ �� ���̸� ����(������ ������� ����)
        return;
    }
    temp = cursor.top(); // ������ �� �� �� (Ŀ�� �̵�)
    cursor.pop(); // ���� Ŀ�� �̵�
    cursor_data.push_back(temp); //������ �� ���� ����
}

void cursor_right() { // D Ŀ���� ���������� ��ĭ �ű�
    char temp;
    if(cursor_data.empty()) { // cursor���� pop�� �����Ͱ� ���� = ������ ���� ���� = ������ �� ��
        return;
    }
    temp = cursor_data.back(); // ����� ������ �� ���� ����
    cursor_data.pop_back(); // ����
    cursor.push(temp); // Ŀ�� ������ �̵�
}

void delete_left() { // B Ŀ�� ���ʿ� �ִ� ���ڸ� ������
    if(cursor.empty()) { // Ŀ���� ���� �� ���̸� ����
        return;
    }
    cursor.pop();
}

void insert_word(char w) { // P $  / $ ���� ���ʿ� �߰�.
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
        cursor.push(cursor_data[k]); // ����� �����͸� �Ųٷ� �־����(�����̶�)
    }

    while(!cursor.empty()) {
        result += cursor.top();
        cursor.pop();
    }

    reverse(result.begin(),result.end());

    cout << result;

    return 0;
}