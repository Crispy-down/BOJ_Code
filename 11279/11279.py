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
    else:
        heapq.heappush(a,(-command,command))
