# 2606. 바이러스 - 실버 3
from collections import deque
n = int(input())
k = int(input())
arr = [[] for _ in range(n+1)]
for i in range(k):
    a,b = map(int,input().split())
    arr[a].append(b)
    arr[b].append(a)
queue = deque([1])
visited = [0 for _ in range(n+1)]
cnt = 0
while queue:
    virus = queue.popleft()
    visited[virus] = 1
    for i in arr[virus]:
        if visited[i] == 0:
            queue.append(i)
            visited[i] = 1
            cnt += 1
print(cnt)