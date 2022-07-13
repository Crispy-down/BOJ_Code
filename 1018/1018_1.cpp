/*
NxM �迭 ��,
8x8 ü������ ���������.
��ĥ�ϴ� ���� �ΰ���. => �� ���� ���� ĭ�� ���/������

�ٵ�, �־��� ���尡 �̷��� ĥ�����ִ� ������ ���
8x8�� �ٽ� �߶󳻾���.
�ٵ�,�̶� �ٽ� ĥ�ؾ��ϴ� ���簢���� �ּҰ����� ���ؾ���.

�׷��ٸ�,
�־��� ���带 ��������,
������ ����� ü���ǰ�
������ �������� ü������ �迭�� �̸� �������� ��,
Ȯ���ϴ� �Լ��� �������.(���Ʈ����=> �迭 ��)

�� ����,
���� Ȯ�ν�
�迭�� �ٸ� ������ ������ ���� ����(vector)

�� vector ���� ���� �ּҰ��� ����ϸ� ��.

�׷���,N M�� 8x8�̻��̸�, Ȯ���ϴ� �Լ� �������� ���� ����.
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