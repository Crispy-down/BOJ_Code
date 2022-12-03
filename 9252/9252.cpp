#include <bits/stdc++.h>
using namespace std;

string str1,str2;
int LCS[1005][1005];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a,b;
    cin >> a >> b;

    str1 = '0' + a;
    str2 = '0' + b;

    int len1 = str1.length();
    int len2 = str2.length();

    for(int i = 0;i<len1;i++) {
        for(int j = 0;j<len2;j++) {
            if(i == 0 || j == 0) {
                LCS[i][j] = 0;
                continue;
            }
            if(str1[i] == str2[j]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else {
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }

    for(int i = 0;i<len1;i++) {
        for(int j = 0;j<len2;j++) {
            cout << LCS[i][j] << " ";
        }
        cout << '\n';
    }



    return 0;
}