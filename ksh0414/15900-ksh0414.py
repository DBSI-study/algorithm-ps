import sys
from collections import deque
input = sys.stdin.readline

def bfs():
    visited = [False] * (n+1)
    visited[1] = True
    q = deque([(1, 0)])
    leaves_depth = 0
    while q:
        now, depth = q.popleft()
        visited[now] = True
        for n_n in tree[now]:
            if not visited[n_n]:
                if len(tree[n_n]) <= 1:
                    leaves_depth += depth+1
                q.append((n_n, depth+1))
    return leaves_depth % 2

n = int(input())
tree = [[] for _ in range(n+1)]
for _ in range(n-1):
    a, b = map(int, input().split())
    tree[a].add(b)
    tree[b].add(a)

if bfs():
    print('Yes')
else:
    print('No')
