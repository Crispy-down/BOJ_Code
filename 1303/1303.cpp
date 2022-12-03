#include <bits/stdc++.h>
#define X first 
#define Y second
using namespace std;

int N,M;
char board[102][102];
int white_v[102][102];
int blue_v[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int white_p = 0;
int blue_p = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    string temp;

    for(int i = 0;i<N;i++) {
        cin >> temp;
        for(int j = 0;j<M;j++) {
            board[i][j] = temp[j];
        }
    }

    queue <pair<int,int>> white_Q;
    queue <pair<int,int>> blue_Q;

    int white_sum;

    for(int i = 0;i<N;i++) { // 하얀색 병사들
        for(int j = 0;j<M;j++) {
            if(board[i][j] != 'W' || white_v[i][j]) {
                continue;
            }
            white_sum = 1; //병사수 초기화(부문마다)
            white_Q.push({i,j});
            white_v[i][j] = 1;
            while(!white_Q.empty()) { //그림과 유사한 문제.
                auto cur = white_Q.front();
                white_Q.pop();
                for(int dir = 0;dir<4;dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
                        continue;
                    }
                    if(board[nx][ny] == 'B' || white_v[nx][ny] == 1) {
                        continue;
                    }
                    white_v[nx][ny] = 1;
                    white_Q.push({nx,ny});
                    white_sum++; // push함과 동시에 병사수 증가
                }
            }  
            white_p += pow(white_sum,2); // 한 부문에 대한 병사수 제곱 최종 결과 변수에 저장
        }
    }

    int blue_sum;

    for(int i = 0;i<N;i++) { // 파란색 병사들
        for(int j = 0;j<M;j++) {
            if(board[i][j] != 'B' || blue_v[i][j]) {
                continue;
            }
            blue_sum = 1;
            blue_Q.push({i,j});
            blue_v[i][j] = 1;
            while(!blue_Q.empty()) {
                auto cur = blue_Q.front();
                blue_Q.pop();
                for(int dir = 0;dir<4;dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
                        continue;
                    }
                    if(board[nx][ny] == 'W' || blue_v[nx][ny] == 1) {
                        continue;
                    }
                    blue_v[nx][ny] = 1;
                    blue_Q.push({nx,ny});
                    blue_sum++;
                }
            }
            blue_p += pow(blue_sum,2);
        }
    }


    cout << white_p << " " << blue_p;

    return 0;
}