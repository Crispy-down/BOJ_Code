#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector <int> &v,int N,int tmp) {
    int left = 0,right = N-1;
    while(left <= right) {
        int mid = (left+right) / 2;
        if(v[mid] == tmp) {
            return 1;
        }
        else if (v[mid] > tmp) {
            right = mid -1;
        }
        else {
            left = mid + 1;
        }
    }
    return 0;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N = 0,M = 0,tmp = 0;
    cin >> N;
    vector <int> v(N);
    for(int i = 0;i<N;i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    cin >> M;
    for(int j = 0;j<M;j++) {
        cin >> tmp;
        cout << search(v,N,tmp) << ' ';
    }
    
    
}