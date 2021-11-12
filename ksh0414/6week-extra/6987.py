from itertools import combinations
import sys
input = sys.stdin.readline

def dfs(cnt):
    global ans, win, draw, lose
    if cnt == 15:
        if win.count(0) == 6 and draw.count(0) == 6 and lose.count(0) == 6:
            ans = 1
        return
    x1, x2 = game[cnt]
    if win[x1] > 0 and lose[x2] > 0:
        win[x1] -= 1
        lose[x2] -= 1
        dfs(cnt+1)
        win[x1] += 1
        lose[x2] += 1

    if lose[x1] > 0 and win[x2] > 0:
        lose[x1] -= 1
        win[x2] -= 1
        dfs(cnt+1)
        lose[x1] += 1
        win[x2] += 1

    if draw[x1] > 0 and draw[x2] > 0:
        draw[x1] -= 1
        draw[x2] -= 1
        dfs(cnt+1)
        draw[x1] += 1
        draw[x2] += 1

game = list(combinations(range(6), 2))
result = []
for i in range(4):
    case = list(map(int, input().split()))
    win, draw, lose = [], [], []
    for j in range(18):
        if j%3 == 0: win.append(case[j])
        elif j%3 == 1: draw.append(case[j])
        else: lose.append(case[j])
    ans = 0
    dfs(0)
    result.append(ans)
print(*result)