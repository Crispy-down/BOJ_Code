#include <bits/stdc++.h>
using namespace std;

int T,N;
int ans;
string name,catag;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        map <string,int> m;

        ans = 1;
        cin >> N;
        while(N--) {
            cin >> name >> catag;
            if(m.find(catag) == m.end()) {
                m[catag] = 1;
            }
            else {
                m[catag]++;
            }
        }

        for(auto i : m) {
            ans *= (i.second + 1);
        }
        cout << ans - 1 << '\n';
    }



    return 0;
}