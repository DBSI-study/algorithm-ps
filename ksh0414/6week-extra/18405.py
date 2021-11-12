import sys
from collections import deque
D = ((1, 0), (0, 1), (-1, 0), (0, -1))

n, k = map(int, input().split())
board = []
q = []
for i in range(n):
    board.append(list(map(int, input().split())))
    for j in range(n):
        if board[i][j] != 0:
            q.append((board[i][j], i, j))
q = deque(sorted(q))
s, x, y = map(int, input().split())
while s > 0:
    for _ in range(len(q)):
        num, i, j = q.popleft()
        for di, dj in D:
            ni, nj = i+di, j+dj
            if (0<=ni<n and 0<=nj<n) and board[ni][nj] == 0:
                board[ni][nj] = num
                q.append((num, ni, nj))
    s -= 1
print(board[x-1][y-1])
