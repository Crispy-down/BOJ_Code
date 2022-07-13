#include <stdio.h>
using namespace std;

int main() {
    int N = 0;
    int num = 0;
    int arr[10001] = {0, };
    scanf("%d",&N);
    for(int i = 0;i<N;i++) { //카운팅 정렬
        scanf("%d",&num);
        arr[num] += 1;
    }

    for(int i = 0;i<10001;i++) {
        for(int j = 0;j<arr[i];j++) { 
            printf("%d \n",i);
        }
    }

    return 0;
}