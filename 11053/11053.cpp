//�迭���� �ּڰ��� ã�� ��
//�� �ε������� ������ ���ϸ� �����ϴ� �κм����� ���ؾ��Ұ� ����
//�ٵ� �迭�� �� �����ϸ� O(N)�ϰŰ����� 
// 
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int *arr = new int[N];

    for(int i = 0;i<N;i++) {
        cin >> arr[i];
    }










    delete[] arr;
    return 0;
}