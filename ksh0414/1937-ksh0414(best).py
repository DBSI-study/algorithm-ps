import sys
input = sys.stdin.readline

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * n for _ in range(n)]
D = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def dfs(x, y):
    if dp[x][y] != 0:
        return dp[x][y]
    dp[x][y] = 1
    for dx, dy in D:
        nx, ny = x+dx, y+dy
        if 0 <= nx < n and 0 <= ny < n:
            if graph[x][y] > graph[nx][ny]:
                dp[x][y] = max(dp[x][y], dfs(nx, ny)+1)
    return dp[x][y]

max_value = 0
for i in range(n):
    for j in range(n):
        max_value = max(max_value, dfs(i, j))
print(max_value)