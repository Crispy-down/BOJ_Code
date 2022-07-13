#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool cmp(tuple <int,int,int> a,tuple <int,int,int> b) {
    return get<1>(a) < get<1>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,temp;
    cin >> n;
    tuple <int,int,int> t1; // original value / original order / xi > xj cnt
    vector <tuple <int,int,int>> v;
    
    for(int i = 0;i<n;i++) {
        cin >> temp;
        t1 = make_tuple(temp,i,0);
        v.push_back(t1);
    }

    sort(v.begin(),v.end()); //sort ascending

    for(int i = 1;i<n;i++) { //compare only front val => sorted by first val
        if(get<0>(v[i-1]) < get<0>(v[i])) {
            get<2>(v[i]) = get<2>(v[i-1]) + 1; 
        }
        else {
            get<2>(v[i]) = get<2>(v[i-1]);
        }
    }

    sort(v.begin(),v.end(),cmp); // sort back with original order

    for(int i = 0;i<n;i++) {
        cout << get<2>(v[i]) << " ";
    }

}