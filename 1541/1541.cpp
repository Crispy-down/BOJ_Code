#include <iostream>
#include <string>
using namespace std;

int main() {
    //�����ؼ� �ΰ� �̻��� �����ڰ� ��Ÿ���� �ʴ´� == + -�� �����ư��鼭 ���´�.
    // �׷��ٸ�,- �� + ��ȣ�� -��, +�� �׳� +�ϸ� �ּҰ��� ���´�.(��ȣ�� ����)
    string str;
    cin >> str;
    int result = 0;
    string num;
    bool isMinus = false; // �� �����ڰ� - �ΰ�?
    for(int i = 0;i<= str.size();i++) {
        if(str[i] == '-' || str[i] == '+' || i == str.size()) {
            if(isMinus) { //�� �����ڰ� -���ٸ� +�����̶� ������
                result -= stoi(num);
                num = "";
            }
            else { // �� �����ڰ� +
                result += stoi(num);
                num = "";
            }
        }
        else { //�����ڸ� ������ ������ ��� ���ڸ� ���ڿ��� ����
            num += str[i];
        }
        if(str[i] == '-') {
            isMinus = true; // - ������ �ڴ� + �����ڰ� ������ �ּҰ��� ���� ��ȣ�� ���� = -����
        }
    }
    cout << result;
}