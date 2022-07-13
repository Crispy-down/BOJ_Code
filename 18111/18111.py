import sys
N,M,B = map(int,sys.stdin.readline().split())
data = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
height = 0
timeans = 10000000000000000000000000000
for i in range(257):
    max = 0
    min = 0
    for j in range(N):
        for k in range(M):
            if data[j][k] < i:
                min += (i - data[j][k])
            else:
                max += (data[j][k] - i)
    inv = max + B
    if inv < min:
        continue
    time = 2*max + min
    if time <= timeans:
        timeans = time
        height = i
print(timeans, height)






    
    



