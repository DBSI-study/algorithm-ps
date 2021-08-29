import sys
input = sys.stdin.readline

n = int(input())
data = []
friend = [set() for _ in range(n)]
for i in range(n):
    data.append(list(map(int, input().split())))

for grade in range(5):
    tmp = [[] for _ in range(10)]
    for i in range(n):
        tmp[data[i][grade]].append(i)
    for cls in tmp:
        if cls != None and len(cls) >= 2:
            for x in cls:
                friend[x].update(cls)

num = 0
ans = 1
for idx, x in enumerate(friend, 1):
    if len(x) > num:
        ans = idx
        num = len(x)
print(ans)