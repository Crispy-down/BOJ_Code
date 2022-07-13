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
//Ǯ�� ������
// ������ ���� ���� ��ȣ�� ������ŭ ���ϸ� ��
// �̴� �������� ������ ���� ����� ���� ������ ���Ѱ�.
// () �̶��� �ݴ� ��ȣ �������� ������ ������ŭ
// ) �׳� �ݴ� ��ȣ�� ������ ���� �þ�� ������ ���� + 1