class Node:
    def __init__(self,item,n):
        self.item = item
        self.next = n

def push(item):
    global front 
    global rear 
    global size 
    new_node = Node(item,None)
    if size == 0:
        front = new_node
    else:
        rear.next = new_node
    rear = new_node
    size += 1

def pop():
    global front
    global rear
    global size
    if size > 0:
        fitem = front.item
        front = front.next
        size -= 1
        print(fitem)
        return fitem
    else:
        rear = None
        print(-1)

def sized():
    global size
    print(size)

def empty():
    global size
    if size == 0:
        print(1)
    else:
        print(0)

def front_item():
    global front
    global size
    if size != 0:
        fitem = front.item
        print(fitem)
    else:
        print(-1)

def rear_item():
    global rear
    global size
    if size != 0:
        ritem = rear.item
        print(ritem)
    else:
        print(-1)
        
front = None
rear = None
size = 0

import sys

N = int(sys.stdin.readline())

for _ in range(N):
    command = sys.stdin.readline().split()
    word = command[0]

    if word == "push":
        item = command[1]
        push(item)
    elif word == "front":
        front_item()
    elif word == "back":
        rear_item()
    elif word == "size":
        sized()
    elif word == "empty":
        empty()
    elif word == "pop":
        pop()




    

