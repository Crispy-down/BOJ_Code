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
    if size != 0:
        top_item = top.item
        top = top.next
        size -= 1
        return top_item
    else:
        size -= 1

top = None
size = 0
hap = 0

import sys
N = int(sys.stdin.readline())
for _ in range(N):
    number = int(sys.stdin.readline())
    if number == 0:
        hap -= pop()
    else:
        push(number)
        hap += number
print(hap)
