import sys
N,M = map(int,sys.stdin.readline().split())
data = list(map(int,sys.stdin.readline().split()))

def binary_search(target):
    start = 0
    end = max(data) 
    while start <= end: #parametric search의 조건
        hs = 0 #가져갈 자른 나무들의 길이 합
        mid = (start + end) // 2 # mid 값 자체가 나무 자를 높이라 생각
        for i in range(len(data)): 
            if data[i] - mid > 0:   
                hs += data[i] - mid
        #자른 나무들의 길이 합을 미리 리스트에 저장하면, 시간초과가 발생함.
        #그래서 바로 반복문 안에서 mid값에 대해 자르고 남는 나무 합 가지고옴
        if hs >= target:
            temp = mid
            start = mid + 1
        # 그래서 구한 나무의 합이 구하려는 나무 합보다 크다?
        # 자를 높이를 올림 == 나무합 적어짐
        # == 최적의 자를 높이 구하기
        # 근데 그 값이 범위가 될수도 있기에 임시 저장하고
        # 마지막까지 탐색하였을 때의 temp값이 최적의 값.
        else:
            end = mid - 1
        # 구한 나무합이 구하려는 나무합보다 작으면
        # 더 밑으로 잘라야함
    return temp
    

print(binary_search(M))









