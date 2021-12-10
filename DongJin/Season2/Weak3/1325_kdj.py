# 1325. 효율적인 해킹 - 실버 2
# bfs 사용. - recursion error
from collections import deque
n,m = map(int,input().split())
arr = [[] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    arr[b].append(a)    # b는 a에게 신뢰받는다. b가 감염되면 a도 감염된다.
hacked = [1 for _ in range(n+1)] # hacked[i] : i를 해킹할 때 감염되는 컴퓨터 수
def bfs(x):
    q = deque([(x,hacked[x])])
    while q:
        temp, temp_hacked = q.popleft()
        if temp_hacked == 1:  # 방문하지 않았다면,
            if len(arr[temp]) != 0: # 신뢰받는 컴퓨터가 있다면 == 감염할 컴퓨터가 더 있다면,
                for k in arr[x]:
                    bfs(k)
                    hacked[x] += hacked[k]
for i in range(1,n+1):
    bfs(i)
max_hacked = max(hacked)
for i in range(1,n+1):
    if hacked[i] == max_hacked:
        print(i, end=" ")