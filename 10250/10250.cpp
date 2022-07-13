#include <iostream>
#include <string>

using namespace std;

int main() {
    int T,H,W,N,cnt= 0;
    cin >> T;
    for(int i =0; i < T;i++) {
        cin >> H >> W >> N;
        int** arr = new int*[H];
        for(int k = 0;k < H;k++) {
            arr[k] = new int[W];
        }
        for(int p = 0; p < H;p++) {
            for(int t = 0; t <W;t++) {
                arr[p][t] = (H-p)* 100 + t + 1;
            }
        }
        for(int w = 0;w < W;w++) {
            for(int y = H-1; y >= 0; y--) {
                cnt += 1;
                if(cnt == N) {
                    cout << arr[y][w] << "\n";
                }
            }
        }
        cnt = 0;
        for(int e = 0;e<H;e++) {
            delete[] arr[e];
        }
        delete[] arr;
    }
    return 0;
}