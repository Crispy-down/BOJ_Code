/*종말의 숫자란, 어떤수에 6이 적어도 3개 이상 연속으로 들어가는 수.
가장 작은 숫자는 666
다음 1666..크기순

N번째로 작은 종말의 숫자를 구하자.(1<= N <= 10000)

이 시리즈를 항상 차례대로 만들때,
N번째 제목을 구하기.

1.연속으로 6이 들어간 조건을 어떻게 확인할 것인가?
=> 666부터 시작하여, 1씩 올려가면 차례대로 올라가서 수를 뽑아 낼 수 있다.
666(1)
1666(2)
2666(3)
3666(4)
4666(5)
5666(6) 
6660(7)
6661(8)
6662(9)
...

숫자 자체를 while문으로 올려가면서,
해당 N번째의 제목일때 출력하기.

어떻게 판단할것인가?
숫자를 올려가면서,
문자열을 활용할 수 있다.

ex)
1666 0 1 2 3
sub(1,3) = "666"
666만 확인해도 된다.
=> 차례대로 올라가기 때문에,
6이 4개가 나와도 앞서 걸러짐.(3개인 구간이 존재.)

안에 부분 string이 있는지 확인해보기.
string "666" 탐색.

string.length()에 따라 시작 지점 다르게하여 탐색.

N = 2,
answer = 1
temp = "666"
 answer ++; => 667

디버깅)
666이 들어있다는 조건이 판명되면
더 조사하지 말고 끊어야한다.
=> 더 조사하면 answer값이 증가함.(6666 => answer += 2)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int movie = 100;
    int answer = 0;

    string mov = "666"; // comp
    string temp; 

    while(answer < N) {
        movie++;
        temp = to_string(movie);
        for(int i = 0;i<temp.length()-2;i++) {
            if(temp.substr(i,3) == mov) {
                answer++;
                break;
            }
        }
    }

    cout << movie;

    return 0;
}