arr = [[0]*15 for _ in range(15)] #2차원 배열 생성 - 초기화

for k in range(15): #2차원 배열 안 원소 삽입 1
    arr[0][k] = k+1 #0층의 원소는 전부 호의 숫자와 같다.
    arr[k][0] = 1 #각 층마다의 1호는 원소값이 다 1이다.
sum = 0
for l in range(1,15): #2차원 배열 안 원소 삽입 2
    for e in range(1,15):
        sum += arr[l-1][e-1] + arr[l-1][e]  #l의 e호의 원소값은 바로 아래층인 l-1층의 e-1호,e호의 원소 합
        arr[l][e] = sum #원소값 삽입
        sum -= arr[l-1][e] #두번 더해지는 원소값 빼기 (ex.arr[0][0]+ arr[0][1] => sum 넣고 arr[0][1] 빼야지 다음 원소값에 이중 덧셈 방지)
    sum = 0 #층 변환시 시그마 값 초기화

T = int(input()) #테스트 케이스 개수

for i in range(T):
    K = int(input()) #층
    N = int(input()) #호
    print(arr[K][N-1])  






    
    
