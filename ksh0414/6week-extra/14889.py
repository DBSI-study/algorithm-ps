import sys
from itertools import combinations
input = sys.stdin.readline

def sum_team(t):
    teams = (t, tuple(base - set(t)))
    result = [0, 0]
    for i in range(2):
        if teams[i] in pre_result:
            result[i] = pre_result[teams[i]]
            continue
        for x, y in combinations(teams[i], 2):
            result[i] += board[x][y]
            result[i] += board[y][x]
        pre_result[teams[i]] = result[i]
    tmp = abs(result[0] - result[1])
    return tmp


n = int(input())
limit = n//2
board = []
team = []
ans = int(1e9)
base = set([i for i in range(n)])
pre_result = {}
for _ in range(n):
    board.append(list(map(int, input().split())))

ans = int(1e9)
for team in combinations([i for i in range(n)], n//2):
    tmp = sum_team(team)
    if tmp:
        ans = min(ans, tmp)
    else:
        ans = tmp
        break
print(ans)