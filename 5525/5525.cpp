#include <bits/stdc++.h>
using namespace std;

int N,M;
int ans_cnt = 0;

string make_str(int n) {
    string ans = "";

    for(int i = 1;i<= 2*n + 1;i++) {
        if(i%2 != 0) {
            ans += 'I';
        }
        else {
            ans += 'O';
        }
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    string find_str;

    cin >> N;
    cin >> M;
    cin >> S;

    int start = 0;
    int size = 2*N + 1;

    if(size > M) {
        cout << 0;
        return 0;
    }

    find_str = make_str(N);

    while(true) {
        if(start + size - 1 > M) {
            break;
        }
        if(find_str == S.substr(start,size)) {
            ans_cnt++;
            start = start + 2;
        }
        else {
            start++;
        }   
    }

    cout << ans_cnt;

}