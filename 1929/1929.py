import sys
M,N = map(int,sys.stdin.readline().split())

def solve(A,B):
    sieve = [False,False] + [True] * (B-1) # 0,1은 소수가 아니기에 패스
    m = int(B ** 0.5) #루트 근 까지의 범위 내(최적화)
    #B의 최대 약수가 sqrt(B) 이하임으로, i = sqrt(B)까지 검사
    for i in range(2, m + 1):
        if sieve[i] == True: #소수 판별
            for j in range(i*i , B+1 , i): #중복제거 최적화,제곱 범위
                sieve[j] = False #배수 지우기
    return [i for i in range(A,B+1) if sieve[i] == True]

[print(i) for i in solve(M, N)] #한줄씩 출력
