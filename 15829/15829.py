
N = int(input())
A = input()
sum = 0
for i in range(N):
   temp = ord(A[i]) % 97 + 1
   sum += temp * (31 ** i)
print(sum % 1234567891)