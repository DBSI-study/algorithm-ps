import sys
from collections import deque
from heapq import heappop, heappush
input = sys.stdin.readline
D = [(1,0), (0, 1), (-1, 0), (0, -1)]

n = int(input())
graph = []
heap = []
move = [[0] * n for _ in range(n)]
ans = 0
for i in range(n):
    graph.append(list(map(int, input().split())))
    for j in range(n):
        heappush(heap, (graph[i][j], i, j))
while heap:
    w, i, j = heappop(heap)
    max_value = 0
    for di, dj in D:
        ni, nj = i+di, j+dj
        if not 0 <= ni < n or not 0 <= nj < n:
            continue
        if w > graph[ni][nj]:
            max_value = max(max_value, move[ni][nj])
    move[i][j] = max_value+1

for line in move:
    ans = max(ans, max(line))
print(ans)