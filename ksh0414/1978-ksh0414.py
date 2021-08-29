import sys
input = sys.stdin.readline

def find(x):
    global parent
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a > b:
        parent[a] = b
    else:
        parent[b] = a

n, m = int(input()), int(input())
parent = [i for i in range(n+1)]
for i in range(1, n+1):
    city = list(map(int, input().split()))
    for n_n, is_connect in enumerate(city, 1):
        if is_connect:
            union(i, n_n)

plan = list(map(int, input().split()))
compare = parent[plan[0]]
flag = True
for x in plan[1:]:
    if parent[x] != compare:
        flag = False
        break
print('YES' if flag else 'NO')