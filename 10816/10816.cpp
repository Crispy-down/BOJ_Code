#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector <int> &v,int tmp) {
    int A,B = 0;
    A = upper_bound(v.begin(),v.end(),tmp) - v.begin();
    B = lower_bound(v.begin(),v.end(),tmp) - v.begin();
    return A-B; 
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,M,tmp= 0; 
    cin >> N;
    vector <int> v(N);
    for(int i = 0;i<N;i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    cin >> M;
    for(int j = 0;j<M;j++) {
        cin >> tmp;
        cout << search(v,tmp) << ' ';
    }
    return 0;
}