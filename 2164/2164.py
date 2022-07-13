from collections import deque
dq = deque([])
import sys

N = int(sys.stdin.readline())

for i in range(1,N+1):
    dq.append(i) #덱에 element 삽입

while True:
    if len(dq) == 1: #element가 하나가 남는순간 break / N=1일땐 바로 break
        break
    dq.popleft() #맨 앞의 element 버리기
    temp = dq.popleft() #그 다음 버린 element 임시저장
    dq.append(temp) #맨 뒤에 임시저장한 element 다시 삽입

for i in range(len(dq)):
    print(dq[i])