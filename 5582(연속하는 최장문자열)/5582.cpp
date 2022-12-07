#include <bits/stdc++.h>
using namespace std;

string str1,str2;
int LCS[4005][4005];
int ans = 0;

void solve_LCS(int x,int y) {
    for(int i = 0;i<x;i++) {
        for(int j = 0;j<y;j++) {
            if(i == 0 || j == 0) {
                LCS[i][j] = 0;
                continue;
            }
            if(str1[i] == str2[j]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
                if(ans < LCS[i][j]) {
                    ans = LCS[i][j];
                }
            }
            else {
                LCS[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string A,B;
    cin >> A >> B;

    str1 = '0' + A;
    str2 = '0' + B;

    int len1 = str1.length();
    int len2 = str2.length();

    solve_LCS(len1,len2);

    cout << ans;

    return 0;
}

// LCS => ���ӵ��� ���� ���� ���� ���ڿ�.
// => �̹����� ���ӵǴ� ���� ���� ���ڿ�.
// ����, str1[i] != str2[j] �϶� LCS[i][j] = 0(�����̶�� ������ ������ ������.)
// ����, ����Ž���� �����ϸ� �ȴ�.