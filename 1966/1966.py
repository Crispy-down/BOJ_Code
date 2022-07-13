from collections import deque
import sys

t = int(sys.stdin.readline())
for _ in range(t):
    N,target = map(int,sys.stdin.readline().split())
    dataq = deque(map(int,sys.stdin.readline().split()))
    index = [0 for _ in range(N)] #중요도 리스트 초기화
    index[target] = 1 #덱이랑 대응되는 리스트,우리가 출력해야할 element 위치
    cnt = 0
    while 1:
        if dataq[0] == max(dataq): #덱의 첫번째 element가 최대값일때,
            if index[0] == 1: #중요도 1순위(출력대상)
                break
            else: #정수 최대값은 맞지만,중요도 1순위는 아닐때,
                dataq.popleft() #맨 앞 element 삭제
                index.pop(0) #중요도 리스트에서도 맨 앞 element 삭제
                cnt += 1 #연산 count 증가
        else:
            dataq.append(dataq.popleft()) #탐색 진행
            index.append(index.pop(0)) #중요도 리스트도 대응
    print(cnt+1) #찾았을 경우 +1

  
