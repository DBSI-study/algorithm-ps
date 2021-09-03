n = int(input())
A, B = 1, 0
for _ in range(n):
    A, B = B, A+B
print(A, B)