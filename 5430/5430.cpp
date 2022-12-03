#include <bits/stdc++.h>
using namespace std;

int T,n;
string input;
string p;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        bool flag = true;
        cin >> p;
        cin >> n;
        cin >> input;
        deque <int> D;

        for(int i = 0;i<input.size();i++) {
            if(input[i] == ']' || input[i] == '[' || input[i] == ',') {
                continue;
            }
            else {
                int res = 0;
                while(true) {
                    res += input[i] - '0';
                    i++;
                    if(input[i] == ']' || input[i] == '[' || input[i] == ',') {
                        D.push_back(res);
                        break;
                    }
                    res *= 10;
                }
            }
        }

        int rev = 0;

        for(int i = 0;i<p.size();i++) {
            if(p[i] == 'R') { // �ѹ��� reverse ���� �ʰ�, R�� ���� ��ŭ �� �������� Reverse �Ѵ�.
                rev = 1 - rev;
            }
            else {
                if(D.empty()) {
                    flag = false;
                    break;
                }
                if(!rev) { // reverse �� ���°� �ƴҶ� pop front(D)
                    D.pop_front();
                }
                else { // reverse �ؾ��� ���¿��� D ������ �ؾ��� ��(�����δ� �������� Reverse �ϴϱ�)
                    D.pop_back(); // pop_back �ϸ� Reverse �ؼ� D������ �Ѱſ� ����.
                }
            }

        }

        if(!flag) {
            cout << "error" << '\n';
        }
        else {
            if(rev) {
                reverse(D.begin(),D.end());
            }
            cout << '[';
            if(D.size() >= 1) {
                for(int i = 0;i<D.size()-1;i++) {
                    cout << D[i] << ',';
                }
                cout << D.back();
            }
            cout << ']' << '\n';
        }
    }


    return 0;
}