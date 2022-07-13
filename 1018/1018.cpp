#include <iostream>
#include <string>
#include <utility> //pair 헤더
#include <algorithm> //min 헤더

using namespace std;
string WB_start[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string BW_start[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};
string arr[50];
int WB_cnt(int x,int y) { //흰색으로 시작하는 체스판과의 비교
    int cnt = 0;
    for(int i = 0; i< 8; i++) {
        for(int j = 0; j< 8; j++) {
            if(arr[i+x][j+y] != WB_start[i][j]) { 
                //arr 배열은 이미 입력받은 배열,받은 인자값 = 변한 좌표값 => 그 좌표값부터의 8 x 8
                cnt++;
            }
        }
    }
    return cnt;
};

int BW_cnt(int x,int y) { //검은색으로 시작하는 체스판과의 비교
    int cnt = 0;
    for(int i = 0; i< 8; i++) {
        for(int j = 0; j< 8; j++) {
            if(arr[i+x][j+y] != BW_start[i][j]) {
                //arr 배열은 이미 입력받은 배열,받은 인자값 = 변한 좌표값 => 그 좌표값부터의 8 x 8
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int cnt;
    int mini = 121213;
    pair<int, int> p1; // pair 생성, "pair<타입1,타입2> 변수이름;"
    cin >> p1.first >> p1.second; //pair 값에 N,M 입력 받음
    for(int i = 0; i < p1.first;i++) {
        cin >> arr[i]; //arr에 값 입력
    }
    for(int i =0; i + 8 <= p1.first; i++) { // N-8 까지의 시작점 이동
        for(int j =0; j + 8 <= p1.second; j++) { // M-8까지의 시작점 이동
            int tmp;
            tmp = min(WB_cnt(i,j),BW_cnt(i,j)); // 최솟값 뽑아내기
            if(tmp < mini) {
                mini = tmp;
            }
        }
    }
    cout << mini;
    return 0;
}
