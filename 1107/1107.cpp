#include <bits/stdc++.h>
using namespace std;

int N;
int ban_cnt;
int ban;
bool ban_num[10];
string check_num;
bool flag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0;i<10;i++) {
        ban_num[i] = true;
    }

    cin >> N;
    cin >> ban_cnt;

    for(int i = 0;i<ban_cnt;i++) {
        cin >> ban;
        ban_num[ban] = false;
    }

    int ans = abs(N - 100);

    for(int pos = 0;pos<=1000000;pos++) {
        flag = true;

        check_num = to_string(pos); // �˻縦 ���� string ��ȯ

        for(int i = 0;i<check_num.size();i++) { // ���ڸ����� üũ (��Ʈ�� Ȱ�� / ���ڸ��� ��ⷯ ����)
            if(!ban_num[check_num[i]-'0']) { // ���峭��ư�� �ִٸ� �Ѿ pos
                flag = false;
                break;
            }
        }

        if(flag) { // ���峭 ��ư�� ���� => �̵�
            if(ans > check_num.size() + abs(N - pos)) { // �ּڰ� ����
                ans = check_num.size() + abs(N - pos);
            }
        }
    }

    cout << ans;

}

// ���� �� Ǯ�� ��� :
// ���Ѱ��� ���Ѱ� �ΰ��� ���� ���ؼ� ���� ���� + �ڸ���  (2��)
// 100������ ���� ���� (1��)
// �� 3���� �ּڰ� ��
// => 80000 8 9 �϶� 77777�� ����-���Ѱ��ε� �ڵ��� �߸���.(��� ���� ����)

// Ǯ�� ���� :( BRUTE FORCE )
// #1. 0 ~ �鸸(or N x 2���� ������ ���� Ž�� => N �ִ� ������ 500000�ε�, 1 ~ 5���� ���峵�ٸ� 0���� 499999�� �ϴ°� ���� 666666���� -�ϴ� ������ �� ����)
// #2. �ش� ���ڿ� ���� �� �ڸ��� ���峵���� �ȳ����� üũ
// #3. �Ȱ��峵�ٸ� �� ä�η� �̵�
// #4. �ڸ��� + N - pos ������ ���� �ĺ�
// #5. solution set �� �ּڰ� ���.

// Ǯ�̹����� ������  ���� �� ���Ϸ������� ����, '���� Ž��' ������ ��ŭ �ϵ��ڵ����� Ʋ�� ����.