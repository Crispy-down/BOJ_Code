def Euclidean(a,b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a

A,B = map(int,input().split())
print(Euclidean(A,B))
print(A*B // Euclidean(A,B))