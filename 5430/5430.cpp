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
            if(p[i] == 'R') { // 한번에 reverse 하지 않고, R의 개수 만큼 맨 마지막에 Reverse 한다.
                rev = 1 - rev;
            }
            else {
                if(D.empty()) {
                    flag = false;
                    break;
                }
                if(!rev) { // reverse 한 상태가 아닐때 pop front(D)
                    D.pop_front();
                }
                else { // reverse 해야한 상태에서 D 연산을 해야할 때(실제로는 마지막에 Reverse 하니까)
                    D.pop_back(); // pop_back 하면 Reverse 해서 D연산을 한거와 같음.
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