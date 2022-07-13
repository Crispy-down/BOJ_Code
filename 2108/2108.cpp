#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int average_num(vector <int> a,int n) {
    double sum = 0;
    for(int i = 0;i<n;i++) {
        sum += a[i];
    }
    sum /= n;
    return round(sum);
}

int middle_num(vector <int> &a,int n) {
    sort(a.begin(),a.end());
    return a[n/2];
}

int most_num(vector <int> a,int n) {
    int count[8001] = {};
    int ttmp = 0;
    vector <int> u;
    for(int i = 0;i< n;i++) {
        count[a[i]+4000]++;
    }
    ttmp = *max_element(count,count + 8001);
    for(int j = 0;j< 8001;j++) {
        if(count[j] == ttmp) {
            u.push_back(j);   
        }
    }
    if(u.size() > 1) {
        return u[1]-4000;
    }
    else {
        return u[0]-4000;
    }
}

int range_num(vector <int> a) {
    return a.back() - a.front();
}

int main() {
    int N = 0;
    int tmp = 0;
    vector <int> v;
    cin >> N;
    for(int i = 0;i<N;i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << average_num(v,N) << endl;
    cout << middle_num(v,N) << endl;
    cout << most_num(v,N) << endl;
    cout << range_num(v) << endl;
    return 0;
}