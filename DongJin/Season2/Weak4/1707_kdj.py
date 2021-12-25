# 1707. 이분 그래프 - 골드4
from collections import deque

def graph(v,e):
    arr = [[] for _ in range(v+1)]
    visited = [0] * (v+1)
    visited[0] = -1
    for _ in range(e):
        x,y = map(int,input().split())
        arr[x].append(y)
        arr[y].append(x)
    for i in range(1,v+1):
        if visited[i] == 0:
            q = deque([(i,0)])  # (현재위치, 이전위치)
            visited[i] = 1
            while q:
                a, previous = q.popleft()
                for b in arr[a]:
                    if b != previous:
                        if visited[b] != 0: # 방문한 접점일 때,
                            if visited[b] == visited[a]:    # 현재와 같은 그룹이면 NO 리턴
                                return "NO"
                        else:
                            visited[b] = 3 - visited[a]
                            q.append((b,a))
    return "YES"
    
K = int(input())
for _ in range(K):
    V,E = map(int,input().split())
    print(graph(V,E))