#include <iostream>
#include <stack>

using namespace std;

int arr[1000000];
stack <int> NGE;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0;i<N;i++) {
        cin >> arr[i];
    }

    int temp;

    for(int i = 0;i<N;i++) {
        if(NGE.empty()) { // ������ ����ִ� ���¶�� idx ����
            NGE.push(i); 
        }
        else { 
            for(int j = 0;j<N;j++) { // N�� ���� �ݺ�
                if(NGE.empty()) { // ������ ��� �ȴٸ� �ش� idx ���� �� break;
                    NGE.push(i);
                    break;
                }
                temp = NGE.top();  // ������ �ֻ��� idx
                if(arr[i] > arr[temp]) { // ������ �ֻ��� ������ �Է¹��� ���� �� ũ�ٸ� �� �Ʒ��δ� ���� (��ū��)
                    arr[temp] = arr[i]; //�ش� ������ �� ���� (��ū��)
                    NGE.pop(); // pop
                }
                else if(arr[i] <= arr[temp]){  // ������ �ֻ��� ������ �Է¹��� ���� ���ų� �۴ٸ�
                    NGE.push(i); // idx ���� �� break;
                    break;
                }
            }
        }
    }

    while(!NGE.empty()) { // ���ÿ� ���� ���ҵ��� ������ -1 (��ū�� �������� ����)
        temp = NGE.top();
        arr[temp] = -1;
        NGE.pop();
    }

    for(int i = 0;i<N-1;i++) {
        cout << arr[i] << " ";
    }
    cout << arr[N-1];

    return 0;
}