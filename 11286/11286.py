import sys
import heapq
N = int(input())
a = []
for _ in range(N):
    command = int(sys.stdin.readline())
    if command == 0:
        if len(a) == 0:
            print(0)
        else:
            print(heapq.heappop(a)[1])
    elif command < 0:
        heapq.heappush(a,(-command,command)) #튜플로 값을 넣으면 첫 번째 원소를 기준으로 우선순위 힙 구성
        #첫 원소 같으면 두 번째 원소 비교 -> 기본 최소힙?
    else:
        heapq.heappush(a,(command,command))