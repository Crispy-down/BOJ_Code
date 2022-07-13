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

    while(pri < n && sub < m) { // N X M 의 교집합 데이터 구하기
    // 두 배열을 정렬 한 후,(오름차순) 
    // 데이터가 같다면 다른 set에 데이터 추가 후 임의의 두 배열 인덱스 증가
        if(see[pri] == hear[sub]) {
            result.push_back(see[pri]);
            cnt += 1;
            pri += 1;
            sub += 1;
        }
    // 한쪽 배열의 데이터가 사전순 순위가 더 높다면 낮은 배열의 인덱스 증가
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