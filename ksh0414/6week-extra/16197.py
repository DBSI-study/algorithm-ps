import sys
from collections import deque
input = sys.stdin.readline
D = ((1, 0), (0, 1), (-1, 0), (0, -1))
X, Y = 0, 1

def bfs():
    result = 11
    visited = set(coins)
    q = deque([(coins, 0)])
    while q:
        now, cnt = q.popleft()
        if cnt >= result:
            continue
        for dx, dy in D:
            next_coin = []
            out = 0
            for coin in now:
                nx, ny = coin[X]+dx, coin[Y]+dy
                if not 0<=nx<r or not 0<=ny<c:
                    out += 1
                    continue

                if (nx, ny) in wall:
                    nx, ny = coin[X], coin[Y]
                next_coin.append((nx, ny))

            next_coin = tuple(next_coin)
            if next_coin not in visited:
                if out == 1:
                    result = min(result, cnt+1)
                else:
                    q.append((next_coin, cnt+1))
                    visited.add(next_coin)
    return result if result <= 10 else -1

r, c = map(int, input().split())
coins = []
walls = []
for i in range(r):
    line = input().rstrip()
    for j in range(c):
        if line[j] == '#':
            walls.append((i, j))
        elif line[j] == 'o':
            coins.append((i, j))

wall = set(walls)
coins = tuple(coins)
print(bfs())