import sys
N = int(sys.stdin.readline())
num = 666
cnt = 0
#10000이하의 수중 연속된 "666"이 나오는 수중
#순서대로 번호를 매긴것.
while True:
    if "666" in str(num): #문자열 안에 666이 있는가
        cnt += 1
    if cnt == N:
        print(num)
        break
    num += 1



