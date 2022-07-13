#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <double> s;

int main() {
    double result;
    int input;
    char temp;
    string formula;
    double pri;
    double sub;

    cin >> input;
    int *arr = new int[input]; // alphabet value
    cin >> formula;

    for(int i = 0;i<input;i++) {
        cin >> arr[i];
    }

    for(int i = 0;i<formula.size();i++) {
        if(formula[i] == '+') {
            pri = s.top();
            s.pop();
            sub = s.top();
            s.pop();
            s.push(double(sub+pri));
        }
        else if(formula[i] == '-') {
            pri = s.top();
            s.pop();
            sub = s.top();
            s.pop();
            s.push(double(sub-pri));
        }
        else if(formula[i] == '*') {
            pri = s.top();
            s.pop();
            sub = s.top();
            s.pop();
            s.push(double(sub*pri));
        }
        else if(formula[i] == '/') {
            pri = s.top();
            s.pop();
            sub = s.top();
            s.pop();
            s.push(double(sub/pri));
        }
        else { // formula[i] - 'A' = ���ĺ��� ����(A = 0,B = 1)... arr[] �ε��� ������ ����� �� �� ���ĺ��� �Ҵ�� ���� ���� ������.
            s.push(arr[formula[i] - 'A']);
        }
    }
    result = s.top();

    cout.precision(2);
    cout << fixed << result << endl;

    delete[] arr;
}