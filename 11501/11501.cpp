#include <bits/stdc++.h>
using namespace std;

int T;
int push;
int N;
vector <int> cost;
long long total = 0;

void pop_and_calculate() {
    int high_cost = cost.back(); // �ְ����� �ְ��� ����
    cost.pop_back(); // �ְ����� ������ �ȵ��� ����

    if(cost.empty()) {
        return;
    }

    while(!cost.empty()) {
        total += (high_cost - cost.back()); // �ְ����� ���� ���� ������ �ֵ� �ְ� ����� ���� ��ȿ� ����
        cost.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> N;
        cin >> push;
        cost.push_back(push); // ù���� �ְ��� ������ �����Ѵ� ����

        for(int i = 1;i<N;i++) {
            cin >> push; // ������ �ְ�
            if(push >= cost.back()) { // i-1 = �� ������ �ְ����� ������ �ְ��� �ö��ٸ�?
                cost.push_back(push); // ����
            }
            else if(push < cost.back()) { // i-1 = �� ������ �ְ����� ������ �ְ��� �������ٸ�?
                pop_and_calculate();
                cost.push_back(push); // ����
            }      
        }

        if(!cost.empty()) {
            pop_and_calculate();
            cout << total << '\n';
        }
        else {
            cout << total << '\n';
        }

        while(!cost.empty()) {
            cost.pop_back();
        }
        // for���� �����µ��� ���Ϳ� ���� �ִ� ���
        // �ְ��� ��� ��� � (�������� ���� �� �Ⱦƾ���)
        // ��� �϶��� (���Ϳ� �ϳ��ۿ� ���� ��)
        total = 0;
    }
}

// �ְ����� ������ ���ؼ�, 
// ���� �˻��� ���� �� ������ �ְ� ������� �ѹ��� ����
// ������, �ְ����� ���� ���� ������ ���ݴ밡 ���� ��
// ex) 1 1 3 1 2
// 3 ����, 3�� ����
// �̷��� �ְ����� �ٽ� ���ؾ��ϳ�?