import sys
N = int(sys.stdin.readline())
data = list(map(int,sys.stdin.readline().split()))

def solve(item):
    sieve = [False,False] + [True] * (1000)
    m = int(1001 ** 0.5) 
    for i in range(2, m + 1):
        if sieve[i] == True: 
            for j in range(i*i , 1002 , i): 
                sieve[j] = False 
    #문제 조건에 맞게 1000 이하의 수에 대해 체로 소수를 골라냄
    if sieve[item] == True: #입력 받은 수가 (idx) 소수면 True값 반환
        return True
    else:
        return False 

cnt = 0
for k in range(len(data)):
    if solve(data[k]) == True:
        cnt += 1
    else:
        continue
print(cnt)



    

