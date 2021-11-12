import sys
from heapq import heappop, heappush
input = sys.stdin.readline
INF = int(1e9)
D = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def dijkstra(x, y):
    distance = [[INF] * c for _ in range(r)]
    distance[0][0] = 0
    q = []
    heappush(q, (0, x, y))
    while q:
        dist, i, j = heappop(q)
        if distance[i][j] < dist:
            continue
        for di, dj in D:
            ni, nj= i+di, j+dj
            if 0 <= ni < r and 0 <= nj < c:
                cost = dist+graph[ni][nj]
                if cost < distance[ni][nj]:
                    distance[ni][nj] = cost
                    heappush(q, (cost, ni, nj))
    print(distance[r-1][c-1])
                

c, r = map(int, input().split())
graph = []
for _ in range(r):
    graph.append(list(map(int, input().strip())))
dijkstra(0, 0)