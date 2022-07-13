/*
NxM 배열 중,
8x8 체스판을 만드려고함.
색칠하는 경우는 두가지. => 맨 왼쪽 위의 칸이 흰색/검은색

근데, 주어진 보드가 이렇게 칠해져있는 보장이 없어서
8x8로 다시 잘라내야함.
근데,이때 다시 칠해야하는 정사각형의 최소갯수를 구해야함.

그렇다면,
주어진 보드를 기준으로,
시작이 흰색인 체스판과
시작이 검은색인 체스판의 배열을 미리 만들어놓은 뒤,
확인하는 함수를 집어넣자.(브루트포스=> 배열 비교)

그 다음,
각각 확인시
배열과 다른 원소의 개수를 따로 저장(vector)

그 vector 안의 값중 최소값을 출력하면 됨.

그런데,N M이 8x8이상이면, 확인하는 함수 시작점을 따로 잡자.
ex) 10 13
0,0 ~ 7,0
0,7 ~ 7,7 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> answer; // min value

char WB_chess[8][8] = {
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W'
};

char BW_chess[8][8] = {
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B'
};

int check_WB(char arr[][50],int row,int col) {
    int change = 0;

    for(int i = 0;i<8;i++) {
        for(int k = 0;k<8;k++) {
            if(arr[i+row][k+col] != WB_chess[i][k]) {
                change++;
            } 
        }
    }

    return change;
}

int check_BW(char arr[][50],int row,int col) {
    int change = 0;


    for(int i = 0;i<8;i++) {
        for(int k = 0;k<8;k++) {
            if(arr[i+row][k+col] != BW_chess[i][k]) {
                change++;
            } 
        }
    }

    return change;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin >> N >> M;

    char input[50][50]; // input arr
    
    for(int i = 0;i<N;i++) {
        for(int k = 0;k<M;k++) {    
            cin >> input[i][k];
        }
    }

    for(int a = 0;a<=N-8;a++) { 
        for(int b = 0;b<=M-8;b++) {
            answer.push_back(check_WB(input,a,b));
        }
    }


    for(int i = 0;i<=N-8;i++) {
        for(int k = 0;k<=M-8;k++) {
            answer.push_back(check_BW(input,i,k));
        }
    }

    cout << *min_element(answer.begin(),answer.end());


    return 0;
}