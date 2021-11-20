# 2573. 빙산 - 골드4
from collections import deque
n, m = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]

dn = [-1,0,1,0]
dm = [0,1,0,-1]

# bfs를 통해 그 좌표와 인접한 바다부분의 개수와 빙산부분의 개수를 알아낸다.
def bfs(start_x,start_y):
    queue = deque([(start_x,start_y)])
    while queue:
        x, y = queue.popleft()
        if visited[x][y] == 0:
            for i in range(4):
                nx = x + dn[i]
                ny = y + dm[i]
                if arr[nx][ny] == 0:  # 주위 바다 개수 세기
                   visited[x][y] += 1
                else:   # 주위에 빙산이 있고, 방문하지 않았다면 queue에 추가
                    if visited[nx][ny] == 0 and 0 < x < n-1 and 0 < y < m-1:
                        queue.append((nx,ny))
            if visited[x][y] == 0:  # a[x][y] 
                visited[x][y] = -1  # 주위에 바다가 없다면, -1로 방문표시.

def check():
    for i in range(1,n-1):
        for j in range(1,m-1):
            if arr[i][j] != 0:
                return True
    return False     

t = 0   # 시간(년)
result = 0  # 결과값

while check():
    visited = [[0] * m for _ in range(n)]
    cnt = 0     # bfs 시행 횟수
    for i in range(1,n-1):
        for j in range(1,m-1):
            if arr[i][j] != 0 and visited[i][j] == 0:
                bfs(i,j)
                cnt += 1
    # bfs를 1회 초과해서 하면 빙산이 분리된 것이므로 결과값을 그때 시간으로 설정하고 break 
    if cnt > 1:
        result = t
        break

    # change arr
    for i in range(n):
        for j in range(m):
            if visited[i][j] < 0:
                continue
            elif arr[i][j] - visited[i][j] < 0:
                arr[i][j] = 0
            else:
                arr[i][j] -= visited[i][j]
    t += 1

print(result)