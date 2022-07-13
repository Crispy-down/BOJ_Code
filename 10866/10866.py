from collections import deque #deque 선언
import sys
dq = deque([]) #생성
def push_front(x): #덱 맨 앞에 값 삽입
    dq.appendleft(x)

def push_back(x): #덱 맨 마지막에 값 삽입
    dq.append(x)

def pop_front(): #덱 맨 앞에 값 삭제
    if len(dq) != 0:
        print(dq.popleft())
    else:
        print(-1)

def pop_back(): #덱 맨 뒤에 값 삭제
    if len(dq) != 0:
        print(dq.pop())
    else:
        print(-1)

def size(): #덱의 크기
    print(len(dq))

def empty(): #덱이 비어있는가?
    if dq:
        print(0)
    else:
        print(1)

def front(): #덱의 맨 앞 요소
    if dq:
        print(dq[0])
    else:
        print(-1)

def back(): #덱의 맨 뒤 요소
    if dq:
        print(dq[-1])
    else:
        print(-1)

N = int(sys.stdin.readline())
for _ in range(N):
    command = sys.stdin.readline().split() #split을 이용하여 인자를 구분하자.
    if command[0] == "push_back":
        push_back(command[1])
    elif command[0] == "push_front":
        push_front(command[1])
    elif command[0] == "front":
        front()
    elif command[0] == "back":
        back()
    elif command[0] == "size":
        size()
    elif command[0] == "empty":
        empty()
    elif command[0] == "pop_front":
        pop_front()
    elif command[0] == "pop_back":
        pop_back()


