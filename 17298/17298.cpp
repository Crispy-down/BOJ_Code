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
        if(NGE.empty()) { // 스택이 비어있는 상태라면 idx 삽입
            NGE.push(i); 
        }
        else { 
            for(int j = 0;j<N;j++) { // N번 동안 반복
                if(NGE.empty()) { // 스택이 비게 된다면 해당 idx 삽입 후 break;
                    NGE.push(i);
                    break;
                }
                temp = NGE.top();  // 스택의 최상위 idx
                if(arr[i] > arr[temp]) { // 스택의 최상의 값보다 입력받은 값이 더 크다면 그 아래로는 전부 (오큰수)
                    arr[temp] = arr[i]; //해당 스택의 값 변경 (오큰수)
                    NGE.pop(); // pop
                }
                else if(arr[i] <= arr[temp]){  // 스택의 최상위 값보다 입력받은 값이 같거나 작다면
                    NGE.push(i); // idx 삽입 후 break;
                    break;
                }
            }
        }
    }

    while(!NGE.empty()) { // 스택에 남은 원소들의 값들은 -1 (오큰수 존재하지 않음)
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