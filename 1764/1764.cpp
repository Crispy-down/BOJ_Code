#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    int cnt = 0;
    cin >> n >> m;

    vector <string> result;

    string *see = new string[n];
    string *hear = new string[m];

    for(int i = 0;i<n;i++) {
        cin >> see[i];
    }

    for(int i = 0;i<m;i++) {
        cin >> hear[i];
    }

    sort(see,see+n);
    sort(hear,hear+m);

    int pri = 0;
    int sub = 0;

    while(pri < n && sub < m) { // N X M �� ������ ������ ���ϱ�
    // �� �迭�� ���� �� ��,(��������) 
    // �����Ͱ� ���ٸ� �ٸ� set�� ������ �߰� �� ������ �� �迭 �ε��� ����
        if(see[pri] == hear[sub]) {
            result.push_back(see[pri]);
            cnt += 1;
            pri += 1;
            sub += 1;
        }
    // ���� �迭�� �����Ͱ� ������ ������ �� ���ٸ� ���� �迭�� �ε��� ����
        else if(see[pri] < hear[sub]) {
            pri += 1;
        }
        else {
            sub += 1;
        }
    }

    sort(result.begin(),result.end());

    cout << cnt << endl;

    for(int i = 0;i<result.size();i++) {
        cout << result[i] << endl;
    }


    delete[] see;
    delete[] hear;

    return 0;
}