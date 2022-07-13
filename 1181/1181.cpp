#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<string,int> a,pair<string,int> b) { //sort 정의 함수
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}

int main() {
    string str = "";
    int N;
    cin >> N;
    vector<pair<string, int>> v; //벡터 안 pair
    
    for(int i =0;i<N;++i) {
        cin >> str;
        v.push_back(make_pair(str, str.length()));
    }

    sort(v.begin(),v.end(),compare);
    v.erase(unique(v.begin(),v.end()), v.end()); //중복제거,erase는 맨 뒤에 값 제거,unique는 중복된 값 맨뒤로 보냄.

    for(int i =0;i<v.size();++i) {
        cout << v[i].first << endl;
    }

    return 0;
}