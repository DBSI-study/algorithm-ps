#while을 통한 bfs 빠르다
import sys
input = sys.stdin.readline
D = ((1, 0), (0, 1), (-1, 0), (0, -1))

r, c = map(int, input().split())
board = []
for _ in range(r):
    board.append(input().rstrip())
ans = 1
stk = [(0, 0, 1, board[0][0])]
while stk:
    i, j, now, visited = stk.pop()
    if now == 26:
        ans = 26
        break
    else:
        ans = max(ans, now)
    for di, dj in D:
        ni, nj = i+di, j+dj
        if 0<=ni<r and 0<=nj<c and board[ni][nj] not in visited:
            stk.append((ni, nj, now+1, visited+board[ni][nj]))
print(ans)
