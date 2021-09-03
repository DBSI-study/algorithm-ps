import sys
input = sys.stdin.readline
D = ((-1, 1), (0, 1), (1, 1)) #위에서부터 탐색

def dfs(i, j):
    global visited
    if j == c-1:
        return True

    for dx, dy in D:
        if 0<=i+dx<r and board[i+dx][j+dy] == '.':
            board[i][j] = 'x'
            if dfs(i+dx, j+dy):
                return True
    return False

r, c = map(int, input().split())
board = []
for _ in range(r):
    board.append(list(input().strip()))

ans = 0
for i in range(r):
    if board[i][0] == '.':
        if dfs(i, 0):
            ans += 1
print(ans)