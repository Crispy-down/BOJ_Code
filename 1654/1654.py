import sys
K,N = map(int,sys.stdin.readline().split())
data = []
for i in range(K):
    data.append(int(sys.stdin.readline()))

def search(target):
    start = 1
    end = max(data)
    temp = 0
    while start <= end:
        cnt = 0
        mid = (start + end) // 2 
        for k in range(len(data)):
            if data[k] // mid >= 0:
                cnt += data[k] // mid
            else:
                continue
        if cnt >= target:
            temp = mid
            start = mid + 1
        else:
            end = mid - 1
    return temp
        
print(search(N))
            

