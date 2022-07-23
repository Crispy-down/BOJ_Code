#include <bits/stdc++.h>
using namespace std;

int N,Bit,x;
string cmd;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0;i<N;i++) {
        cin >> cmd;
        if(cmd == "add") {
            cin >> x;
            Bit |= (1 << x);
        }
        else if(cmd == "remove") {
            cin >> x;
            Bit &= ~(1 << x);

        }
        else if(cmd == "check") {
            cin >> x;
            if(Bit & (1 << x)) {
                cout << 1 << '\n';
            } 
            else {
                cout << 0 << '\n';
            }
        }
        else if(cmd == "toggle") {
            cin >> x;
            Bit ^= (1 << x);
        }
        else if(cmd == "all") {
            Bit = (1 << 21) - 1;
        }
        else if(cmd == "empty") {
            Bit = 0;

        }
    }
    return 0;
}