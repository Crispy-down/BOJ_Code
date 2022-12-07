#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> v;
int arr[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(N>0){
        v.push_back(N%10);
        N /= 10;
    }

    for(int i = 0;i<v.size();i++) {
        arr[v[i]]++;
    }

    int div = (arr[6] + arr[9] + 1) / 2;
    arr[6] = div;
    arr[9] = div;

    cout << *max_element(arr,arr+10);

    return 0;
}

// N �ް� 10���� ��ⷯ ���� �� 0�� �ɶ� ���� 10���� ����
// ���Ϳ� ���ڸ� �� �� ����
// ����
// 1 ~ 9 �ߺ��ؼ� �� ����Ǿ�����
// �ִ� 7��
// 6,9 ���� ���� �ߺ��Ǿ����� �� +1
// 6 9�� ���� ����.
// ex) 9 9 9 9 -> 6 ��ü ����, ��Ʈ 2��.
// int arr[n] ++ (�Ϸ� Ž��)
// 6�̳� 9�� ������ 