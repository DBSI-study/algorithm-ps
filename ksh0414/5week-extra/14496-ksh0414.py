import sys
from heapq import heappop, heappush
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start, end):
    heap = []
    distance = [INF] * (n+1)
    heappush(heap, (0, start))
    distance[start] = 0

    while heap:
        dis, now = heappop(heap)
        if dis > distance[now]:
            continue
        
        for n_n, w in graph[now]:
            cost = dis + w
            if cost < distance[n_n]:
                distance[n_n] = cost
                heappush(heap, (cost, n_n))
    
    return distance[end]

a, b = map(int, input().split())
n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append((y, 1))
    graph[y].append((x, 1))

ans = dijkstra(a, b)
print(ans if ans < INF else -1)