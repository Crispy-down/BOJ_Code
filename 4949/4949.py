import sys
stack = []
while 1:
    N = sys.stdin.readline().rstrip() # rstrip은 오른쪽 개행문자 제거.
    if N == ".":
        break
    for i in range(len(N)):
        if N[i] == "(":
            stack.append("(")
        elif N[i] == "[":
            stack.append("[")
        elif N[i] == ")":
            if len(stack) != 0 and stack[-1] == "(": #top 원소랑 비교
                stack.pop()
            else:
                stack.append("+") #len(stack) == 0 되는 조건을 피하기위해 추가함,다른 뜻은 없음
                break
        elif N[i] == "]":
            if len(stack) != 0 and stack[-1] == "[":
                stack.pop()
            else:
                stack.append("+")
                break
        elif N[i] == ".":
            break
        else:
            continue
    if len(stack) == 0:
        print("yes")
    else:
        print("no")
    stack = []
        

        


    