#include <bits/stdc++.h>
using namespace std;

int LCS[1002][1002];
string str1,str2;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A,B;
    cin >> A >> B;
    
    str1 = '0' + A;
    str2 = '0' + B; // LCS 배열 초기값을 위한 작업(string 맨 앞 0)

    int len1 = str1.length();
    int len2 = str2.length();

    for(int i = 0;i<len1;i++) {
        for(int j = 0;j<len2;j++) {
            if(i == 0 || j == 0) { // initialize
                LCS[i][j] = 0;
                continue;
            }
            if(str1[i] == str2[j]) { // 각각 i,j번째의 문자가 같은 경우
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else { // 문자가 다른경우
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }

    cout << LCS[len1-1][len2-1] << '\n';
    
    return 0;
}
// LCS ( Longest Common Subsequence )
// * subsequence => 연속되지 않은 최장 문자열
// LCS(Xi,Yj) => 
// i = 0 or j = 0 => LCS[i][j] = 0
// Xi == Yj => LCS[i][j] = LCS[i-1][j-1] + 1 
// (이전까지의 공통 문자열 길이 + i,j번째의 동일 문자 1개)
// Xi != Yj => LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]) 
// (이전까지의 공통문자열 ~j까지의 문자열 길이 / ~i까지의 문자열 길이 중 최장 문자열 길이 선택)
