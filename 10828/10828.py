class Node:
    def __init__(self, item, link):
        self.item = item
        self.next = link

def push(item):
    global top
    global size 
    top = Node(item, top)
    size += 1

def pop():
    global top
    global size
    if size != 0:
        top_item = top.item
        top = top.next
        size -= 1
        print(top_item)
    else:
        print(-1)

def sized(): 
    global size
    if size < 0:
        print(0)
    else:
        print(size)

def empty():
    global size
    if size == 0:
        print(1)
    else:
        print(0)

def toped():
    global top
    if size != 0:
        top_item = top.item
        print(top_item)
    else:
        print(-1)

top = None
size = 0

import sys

N = int(sys.stdin.readline())

for _ in range(N):
    word = sys.stdin.readline().split()
    order = word[0]
    
    if order == "push":
        item = word[1]
        push(item)
    elif order == "pop":
        pop()
    elif order == "size":
        sized()
    elif order == "empty":
        empty()
    elif order == "top":
        toped()