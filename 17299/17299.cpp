#include <iostream>
#include <stack>

using namespace std;

int N;
int F[1000001];
int input[1000001];
stack <int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0;i<N;i++) {
        cin >> input[i];
        F[input[i]]++;
    }

    int temp;

    for(int i = 0;i<N;i++) {
        if(s.empty()) { // ������ ����ִٸ� idx ����
            s.push(i);
        }
        else { // ���ÿ� ���� �ִ� ���
            for(int k = 0;k<N;k++) { // N��
                if(s.empty()) { // ������ ����� ��� push�ϰ� break;
                    s.push(i);
                    break;
                }
                temp = s.top(); // idx
                if(F[input[i]] > F[input[temp]]) { // F�� �� => ���ÿ� �ִ� �ֻ��� idx���� �Է°��� ���� F �� / ���� �Է� idx�� ���� F��
                    input[temp] = input[i]; // ����ū�� ����
                    s.pop(); 
                }
                else {
                    s.push(i); // ���� ���ų� �۴ٸ� �׳� push(�������� ����)
                    break;
                }
            }
        }
    }

    while(!s.empty()) { // N�� �ݺ� �� �����ִ� ��ҵ��� ���� ����ū���� ����
        temp = s.top();
        input[temp] = -1;
        s.pop();
    }

    for(int i = 0;i<N-1;i++) {
        cout << input[i] << " ";
    }
    cout << input[N-1];

    return 0;
}