from collections import deque
INF = int(1e9)
N = int(input())

def bfs(start):
    q = deque([(0, start)])
    visited = [False] * N
    visited[start] = True
    distance = [int(1e9)] * N
    while q:
        dist, now = q.popleft()
        cost = dist+1
        for n_n in graph[now]:
            if not visited[n_n]:
                q.append((cost, n_n))
                visited[n_n] = True
                distance[n_n] = cost
    return min([distance[e] for e in end])

metros = []
graph = [[] for _ in range(N)]
start = []
for i in range(N):
    tmp = tuple(map(int, input().split()))
    metros.append(set(tmp[1:]))
    if 0 in metros[i]:
        start.append(i)
    for j in range(i-1, -1, -1):
        for station in metros[j]:
            if station in metros[i]:
                graph[i].append(j)
                graph[j].append(i)
                break

destination = int(input())
end = []
ans = True
for station in range(N):
    if station in start:
        ans = 0
        break
    if destination in metros[station]:
        end.append(station)
if ans:
    ans = min([bfs(s) for s in start])
print(ans if ans != INF else -1)