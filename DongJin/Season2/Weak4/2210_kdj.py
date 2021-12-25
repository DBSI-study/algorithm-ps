# 2210. 숫자판 점프 - 실버2
# bfs로 접근
from collections import deque
numbers = [list(input().split()) for _ in range(5)]
result = []  # 만든 여섯자리 수 저장
dx, dy = (1,-1,0,0),(0,0,1,-1)
def bfs(m,n):
    q = deque([(m,n,"")])
    while q:
        x,y,num = q.popleft()
        if len(num) == 6:
            if num not in result:   # 중복 고려
                result.append(num)
            continue
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < 5 and 0 <= ny < 5:
                q.append((nx,ny,num+numbers[nx][ny]))
for i in range(5):
    for j in range(5):
        bfs(i,j)
print(len(result))