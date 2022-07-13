#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,s;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0;i<n;i++) {
        cin >> arr[i];
    }
    cin >> s;

    for(int i = 0;i<n;i++) { // ������ ���� ���� ���� == ���� ū���� �迭 ù��°�� �����ϱ�
        int max = arr[i]; 
        int maxi = i;
        for(int j = i+1;j<n;j++) {
            if(s-(j-i) >= 0) {
                if(max < arr[j]) {
                    max = arr[j];
                    maxi = j;
                }
            }
        }
        for(int j = maxi;j>i;j--) {
            swap(arr[j],arr[j-1]); //�ִ밪�� �ű�� �ִ� Ƚ�� ������ �������� ������ ������ �о��
        }
        s -= (maxi - i); // �ű� Ƚ�� ����
        if(s <= 0) {
            break;
        }
    }

    for(int i = 0;i<n;i++) {
        cout << arr[i] << " ";
    } // answer
    delete[] arr;
}