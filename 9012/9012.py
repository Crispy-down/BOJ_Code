class Node:
    def __init__(self,item,link):
        self.item = item
        self.next = link

def push(item):
    global top
    global size
    top = Node(item,top)
    size += 1

def pop():
    global top
    global size
    if size > 0:
        top = top.next
        size -= 1
    else:
        size -= 1

top = None
size = 0

import sys
N = int(sys.stdin.readline())
for _ in range(N):
    command = sys.stdin.readline().strip()
    for i in range(len(command)):
        if command[i] == "(":
            push("(")
        elif command[i] == ")":
            pop()
            if size < 0: #size가 음수가 되는 순간 성립하지 않는다.
                break
        else:
            continue
    if size == 0:
        print("YES")
    else:
        print("NO")
        
    size = 0
    top = None
    


