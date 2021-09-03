import sys
input = sys.stdin.readline

n = int(input())
board = []
for _ in range(n):
    board.append(list(map(int, input().split())))

dp = [[0] * n for _ in range(n)]
dp[0][0] = 1
for i in range(n):
    for j in range(n):
        move = board[i][j]
        cnt = dp[i][j]
        if move == 0:
            continue
        if i+move < n:
            dp[i+move][j] += cnt
        if j+move < n:
            dp[i][j+move] += cnt
print(dp[n-1][n-1])