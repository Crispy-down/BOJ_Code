#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

void func(int k) { // ���� k������ ���� ������.
    if(k == m) { // m���� ��� ��������
        for(int i = 0;i<m;i++) {
            cout << arr[i] << ' '; // arr�� ����ص� ���� ���
        }
        cout << '\n';
        return;
    }

    for(int i = 1;i<=n;i++) { // 1���� n������ ���� ����,
        if(!isused[i]) { // ���� i�� ������ �ʾ�����
            arr[k] = i; // k��° ���� i�� ����
            isused[i] = 1; // i�� ���Ǿ��ٰ� ǥ��
            func(k+1); // ���� ���� ���Ϸ� �� �ܰ� �� ��
            isused[i] = 0; // k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ�� ������ i�� ���� ��� �ȵǾ���
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    func(0);
}