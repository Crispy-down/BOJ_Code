import sys
N = int(sys.stdin.readline())
Ndata = list(map(int,sys.stdin.readline().split()))
M = int(sys.stdin.readline())
Mdata = list(map(int,sys.stdin.readline().split()))
Ndata.sort()

def search(item):
    start = 0
    end = len(Ndata) - 1 #index 값으로 start,end 포인터 조정
    while start <= end:
        mid = (start + end) // 2 #mid 값 자체가 Ndata 안에 존재 하지 않을 수 있음
        #ex) 4 1 2 5 6 mid == 3일때 3을 찾지 못함
        if item == Ndata[mid]: #따라서 index값을 이용해 찾기
            return Ndata[mid]
        elif item > Ndata[mid]:
            start = mid + 1
        else:
            end = mid - 1
    return None
    

for i in range(len(Mdata)):
    if search(Mdata[i]) == Mdata[i]:
        print("1")
    else:
        print("0")



        


