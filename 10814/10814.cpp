#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(pair<int,string> a,pair<int,string> b) {
    return a.first < b.first;
} 

int main() {
    int N;
    cin >> N;
    pair<int,string> tmp;
    vector<pair<int,string>> v;
    for(int i =0;i<N;++i) {
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    stable_sort(v.begin(),v.end(),cmp);
    for(int i =0;i<N;++i) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}