#include <bits/stdc++.h>
using namespace std;

int N;
int arr[130][130];
int blue_paper = 0;
int white_paper = 0;

void solve(int x,int y,int n) {
    if(n == 1) {
        if(arr[x][y] == 1) {
            blue_paper++;
        }
        else if(arr[x][y] == 0) {
            white_paper++;
        }
        return;
    }

    int sim = arr[x][y];
    bool div = false;

    for(int i = x;i<x+n;i++) {
        for(int j = y;j<y+n;j++) {
            if(sim != arr[i][j]) {
                div = true;
                break;
            }
        }
    }

    if(div) {
        solve(x,y,n/2);
        solve(x,y+n/2,n/2);
        solve(x+n/2,y,n/2);
        solve(x+n/2,y+n/2,n/2);
    }
    else {
        if(sim == 0) {
            white_paper++;
        }
        else if(sim == 1) {
            blue_paper++;
        }
    }

    return;
}

int main() {
    cin >> N;

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    solve(0,0,N);

    cout << white_paper << '\n';
    cout << blue_paper;

}
