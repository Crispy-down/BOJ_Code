#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N = 0;
    scanf("%d",&N);
    pair<int,int> tmp;
    vector<pair<int,int>> v;
    v.reserve(100001);
    for(int i =0;i<N;++i) {
        scanf("%d %d",&tmp.first,&tmp.second); 
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i =0;i<v.size();++i) {
        printf("%d %d \n",v[i].first,v[i].second);
    }
    return 0;
}