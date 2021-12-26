# 2589. 보물섬 - 골드5
# 무작정 bfs 최대 2500번하기!
# pypy3로 하니 통과!
from collections import deque
dx,dy = (1,-1,0,0),(0,0,1,-1)
def bfs(a,b):
    q = deque([(a,b,0)])
    visited = [[0]*c for _ in range(r)]
    visited[a][b] = 1
    time = 0
    while q:
        x,y,distance = q.popleft()
        time = max(time,distance)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < r and 0 <= ny < c:
                if arr[nx][ny] == "L" and visited[nx][ny] != 1:
                    visited[nx][ny] = 1
                    q.append((nx,ny,distance+1))
    return time

r,c = map(int,input().split())
land = []
arr = []
t = 0
for i in range(r):
    input_list = list(input().strip())
    arr.append(input_list)
    for j in range(c):
        if input_list[j] == "L":
            land.append((i,j))
for x,y in land:
    t = max(t,bfs(x,y))
print(t)