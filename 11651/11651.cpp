#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int N = 0;
    scanf("%d",&N);
    pair<int,int> tmp;
    vector<pair<int,int>> v;
    for(int i = 0;i<N;i++) {
        scanf("%d %d",&tmp.first,&tmp.second);
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp);

    for(int i = 0;i<v.size();i++) {
        printf("%d %d \n",v[i].first,v[i].second);
    }

    return 0;
}