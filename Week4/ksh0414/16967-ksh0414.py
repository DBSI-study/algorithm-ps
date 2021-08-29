H, W, X, Y = map(int, input().split())
A = []
B = []
for _ in range(H):
    tmp = list(map(int, input().split()))
    B.append(tmp)
    A.append(tmp[:W])
    
for r in range(X, H):
    for c in range(Y, W):
        A[r][c] -= A[r-X][c-Y]

for z in A:
    print(*z)