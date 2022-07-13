#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N = 0;
    int tmp = 0;
    vector <int> v;
    scanf("%d",&N);
    for(int i = 0;i < N;i++) {
        scanf("%d",&tmp);
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++) {
        printf("%d \n",v[i]);
    }


    return 0;
}