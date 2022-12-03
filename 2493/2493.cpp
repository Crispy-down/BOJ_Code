#include <bits/stdc++.h>
using namespace std;

int N;
int H;
stack <pair<int,int>> S;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1;i<=N;i++) {
        cin >> H; // ���� �Է�
        while(!S.empty()) { // ������ ������� �ʴٸ�
            if(S.top().second > H) { // �ֻ��� ž ���� ���̰� �Է¹��� ���̺��� ũ��
                cout << S.top().first << ' '; // �׷� �ű⼭ ������
                break;
            }
            S.pop(); // top�� ���̰� ũ�� �ʴٸ� �׸� pop(�ٸ������� ������)
            // ���ʿ� ���̰� ũ���ʴٴ°Ŵ� ���� �ʿ䰡 ���ٴ°�, ���� �׸� ����
        }

        if(S.empty()) { // �ʱⰪ�̳� ����ִٸ� ���Ұ� ���� => ���� x
            cout << "0 ";
        }

        S.push({i,H}); // Ÿ�� �ε����� ���̸� �������
    }

    return 0;
}