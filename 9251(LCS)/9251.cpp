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
    str2 = '0' + B; // LCS �迭 �ʱⰪ�� ���� �۾�(string �� �� 0)

    int len1 = str1.length();
    int len2 = str2.length();

    for(int i = 0;i<len1;i++) {
        for(int j = 0;j<len2;j++) {
            if(i == 0 || j == 0) { // initialize
                LCS[i][j] = 0;
                continue;
            }
            if(str1[i] == str2[j]) { // ���� i,j��°�� ���ڰ� ���� ���
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else { // ���ڰ� �ٸ����
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }

    cout << LCS[len1-1][len2-1] << '\n';
    
    return 0;
}
// LCS ( Longest Common Subsequence )
// * subsequence => ���ӵ��� ���� ���� ���ڿ�
// LCS(Xi,Yj) => 
// i = 0 or j = 0 => LCS[i][j] = 0
// Xi == Yj => LCS[i][j] = LCS[i-1][j-1] + 1 
// (���������� ���� ���ڿ� ���� + i,j��°�� ���� ���� 1��)
// Xi != Yj => LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]) 
// (���������� ���빮�ڿ� ~j������ ���ڿ� ���� / ~i������ ���ڿ� ���� �� ���� ���ڿ� ���� ����)
