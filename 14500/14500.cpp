#include <iostream>
#include <algorithm>
using namespace std;

int one_four(int **arr,int N,int M) {
    int pri = 0; // maxi
    int sub = 0;

    for(int i = 0;i<N;i++) { // ¤Ñ
        for(int k = 0;k<M-3;k++)  {
            sub = arr[i][k] + arr[i][k+1] + arr[i][k+2] + arr[i][k+3];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-3;i++) { // ¤Ó
        for(int k = 0;k<M;k++) {
            sub = arr[i][k] + arr[i+1][k] + arr[i+2][k] + arr[i+3][k];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    return pri;
}

int two_two(int ** arr,int N,int M) { // ¤±
    int pri = 0;
    int sub = 0;

    for(int i = 0;i<N-1;i++) {
        for(int k = 0;k<M-1;k++) {
            sub = arr[i][k] + arr[i][k+1] + arr[i+1][k] + arr[i+1][k+1];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    return pri;
}

int three_one(int **arr,int N,int M) {
    int pri = 0;
    int sub = 0;

    for(int i = 0;i<N-2;i++) { // 3 x 1 rotate
        for(int k = 0;k<M-1;k++) {
            sub = arr[i][k] + arr[i+1][k] + arr[i+2][k] + arr[i+2][k+1];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-1;i++) { // debugging
        for(int k = 0;k<M-2;k++) {
            sub = arr[i+1][k] + arr[i+1][k+1] + arr[i+1][k+2] + arr[i][k+2];
            if(pri < sub) {
                pri = sub;
            }
        } 
    }

    for(int i = 0;i<N-2;i++) {
        for(int k = 0;k<M-1;k++) {
            sub = arr[i][k] + arr[i][k+1] + arr[i+1][k+1] + arr[i+2][k+1];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-1;i++) {
        for(int k = 0;k<M-2;k++) {
            sub = arr[i][k+1] + arr[i][k] + arr[i][k+2] + arr[i+1][k];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    return pri;
}

int three_one_symmetric(int **arr,int N,int M) {
    int pri = 0;
    int sub = 0;

    for(int i = 0;i<N-2;i++) {
        for(int k = 0;k<M-1;k++) {
            sub = arr[i][k+1] + arr[i+1][k+1] + arr[i+2][k+1] + arr[i+2][k];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-1;i++) {
        for(int k = 0;k<M-2;k++) {
            sub = arr[i][k] + arr[i][k+1] + arr[i][k+2] + arr[i+1][k+2];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-2;i++) {
        for(int k = 0;k<M-1;k++) {
            sub = arr[i][k] + arr[i+1][k] + arr[i+2][k] + arr[i][k+1];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-1;i++) {
        for(int k = 0;k<M-2;k++) {
            sub = arr[i][k] + arr[i+1][k] + arr[i+1][k+1] + arr[i+1][k+2];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    return pri;
}

int two_by_two(int **arr,int N,int M) {
    int pri = 0;
    int sub = 0;

    for(int i = 0;i<N-2;i++) {
        for(int k = 0;k<M-1;k++) {
            sub = arr[i][k] + arr[i+1][k] + arr[i+1][k+1] + arr[i+2][k+1];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-1;i++) {
        for(int k = 0;k<M-2;k++) {
            sub = arr[i+1][k] + arr[i+1][k+1] + arr[i][k+1] + arr[i][k+2];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-2;i++) {
        for(int k = 0;k<M-1;k++) {
            sub = arr[i+1][k] + arr[i+2][k] + arr[i+1][k+1] + arr[i][k+1];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-1;i++) {
        for(int k = 0;k<M-2;k++) {
            sub = arr[i][k] + arr[i][k+1] + arr[i+1][k+1] + arr[i+1][k+2];
            if(pri < sub) {
                pri = sub;
            }
        }
    }


    return pri;
}

int three_down(int **arr,int N,int M) {
    int pri = 0;
    int sub = 0;

    for(int i = 0;i<N-1;i++) {
        for(int k = 0;k<M-2;k++) {
            sub = arr[i][k] + arr[i][k+1] + arr[i][k+2] + arr[i+1][k+1];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-2;i++) {
        for(int k = 0;k<M-1;k++) {
            sub = arr[i][k] + arr[i+1][k] + arr[i+2][k] + arr[i+1][k+1];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-1;i++) {
        for(int k = 0;k<M-2;k++) {
            sub = arr[i+1][k] + arr[i][k+1] + arr[i+1][k+1] + arr[i+1][k+2];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    for(int i = 0;i<N-2;i++) {
        for(int k = 0;k<M-1;k++) {
            sub = arr[i][k+1] + arr[i+1][k] + arr[i+1][k+1] + arr[i+2][k+1];
            if(pri < sub) {
                pri = sub;
            }
        }
    }

    return pri;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    int result[6] = {0};

    int ** arr = new int*[N]; // N x M arr dynamic allocation by two pointer
    for(int i = 0;i<N;i++) {
        arr[i] = new int[M];
    }

    for(int i = 0;i<N;i++) { // input values into arr
        for(int k = 0;k<M;k++) {
            cin >> arr[i][k];
        }
    }
    
    result[0] = one_four(arr,N,M);
    result[1] = two_two(arr,N,M);
    result[2] = three_one(arr,N,M);
    result[3] = three_one_symmetric(arr,N,M);
    result[4] = two_by_two(arr,N,M);
    result[5] = three_down(arr,N,M);   
    
    int max = *max_element(result,result+6);
    cout << max; 

    for(int i = 0;i<N;i++) { // release allocation
        delete[] arr[i];
    }
    delete[] arr; 

    return 0;
}