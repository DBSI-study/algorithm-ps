import sys
from collections import deque
input = sys.stdin.readline
D = ((1, 0), (0, 1), (-1, 0), (0, -1))

def play(i, j):
    q = deque([(i, j)])
    visited[i][j] = ans
    union = [(i, j)]
    total = board[i][j]
    cnt = 1

    while q:
        x, y = q.popleft()
        now = board[x][y]
        for dx, dy in D:
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<n and visited[nx][ny] != ans and l <= abs(now - board[nx][ny]) <= r:
                visited[nx][ny] = ans
                union.append((nx, ny))
                q.append((nx, ny))
                total += board[nx][ny]
                cnt += 1
    
    if cnt > 1:
        population = total // cnt
        for x, y in union:
            board[x][y] = population
            search_list.append((x, y))
        return True
    return False


n, l, r = map(int, input().split())
board = []
search_list = deque()
for i in range(n):
    board.append(list(map(int, input().split())))
    for j in range(n):
        search_list.append((i, j))

ans = 0
visited = [[-1] * n for _ in range(n)]
while True:
    flag = False
    for _ in range(len(search_list)):
        i, j = search_list.popleft()
        if visited[i][j] != ans:
            if play(i, j):
                flag = True
    if not flag:
        break
    ans += 1
print(ans)