import sys
input = sys.stdin.readline
D = ((1, 0), (0, 1), (-1, 0), (0, -1))

def bfs():
    global ans
    q = set([(0, 0, board[0][0])])
    while q:
        i, j, visited = q.pop()
        now = len(visited)
        if now > ans:
            ans = now
            if ans == 26:
                return
        for di, dj in D:
            ni, nj = i+di, j+dj
            if 0<=ni<r and 0<=nj<c and board[ni][nj] not in visited:
                q.add((ni, nj, visited+board[ni][nj]))

r, c = map(int, input().split())
board = []
ans = 0
for _ in range(r):
    board.append(input().rstrip())
bfs()
print(ans)