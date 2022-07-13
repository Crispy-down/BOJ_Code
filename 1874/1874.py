stack = []
answer = []
flag = 0
cur = 1
import sys
n = int(sys.stdin.readline())
for i in range(n):
    num = int(sys.stdin.readline()) #첫 번째로 pop할 element를 입력받음
    while cur <= num: #cur = num일때까지 while문 돌기
        stack.append(cur) #직접 연산을 할 스택에 값 push
        answer.append("+") #연산의 결과를 다른 list에 저장(답)
        cur += 1 #첫 번째로 pop할 element까지 값을 증가하면서 push
    if stack[-1] == num: #top이 pop할 element와 같은 경우
        stack.pop() #직접 연산하는 스택에서 pop
        answer.append("-") #연산 결과 저장
    else: #오름차순으로 push한 element가,pop할 때 순서가 지켜지지 않는 경우
        #ex) num = 3 -> 4되는 경우,
        #이미 스택엔 3 이하로 element가 존재할 텐데 
        #그 이상의 element를 가져오지 못한다.
        #즉,top이 num보다 크면 성립이고 아니면 가져오지 못함.
        print("NO") #NO 출력
        flag = 1 #이 경우에는 연산의 결과를 출력할 필요가 없다.
        break
if flag == 0: #정상적으로 연산을 한 경우,결과 출력
    for i in answer:
        print(i)




