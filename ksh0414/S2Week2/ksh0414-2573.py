import sys
from collections import deque
input = sys.stdin.readline
D = ((1, 0), (0, 1), (-1, 0), (0, -1))

def is_separated():
    cnt = 0
    visited = set()
    for x, y in ice:
        if (x, y) not in visited:
            cnt += 1
            if cnt > 1:
                break
            visited.add((x, y))
            q = deque([(x, y)])
            while q:
                i, j = q.popleft()
                for di, dj in D:
                    ni, nj = i+di, j+dj
                    if not (ni, nj) in visited and (ni, nj) in ice:
                        visited.add((ni, nj))
                        q.append((ni, nj))      
    return False if cnt == 1 else True

def play():
    tmp = []
    for x, y in ice:
        cnt = 0
        for dx, dy in D:
            nx, ny = x+dx, y+dy
            if 0<=nx<r and 0<=ny<c and board[nx][ny] <= 0:
                cnt += 1
        tmp.append((x, y, cnt))
            
    for x, y, cnt in tmp:
        board[x][y] -= cnt
        if board[x][y] <= 0:
            ice.remove((x, y))

r, c = map(int, input().split())
board = []
ice = set()
for i in range(r):
    tmp = list(map(int, input().split()))
    board.append(tmp)
    for j in range(c):
        if tmp[j] != 0:
            ice.add((i, j))
time = 0
while not is_separated():
    play()
    time += 1
print(time if ice else 0)