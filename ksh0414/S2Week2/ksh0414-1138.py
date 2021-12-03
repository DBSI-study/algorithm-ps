n = int(input())
data = list(map(int, input().split()))
arr = []
for i in range(n, 0, -1):
    arr.insert(data[i-1], i)
print(*arr)