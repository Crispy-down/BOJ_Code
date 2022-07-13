from collections import deque
dq = deque([])
import sys
N,K = map(int,sys.stdin.readline().split())
for i in range(1,N+1):
    dq.append(i)
print('<',end ='')
while dq:
    for i in range(K-1):
        dq.append(dq[0])
        dq.popleft()
    print(dq.popleft(),end='')
    if dq:
        print(', ',end='')
print('>')
    





