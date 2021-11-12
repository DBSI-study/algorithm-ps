# 리프노드들의 1까지의 거리의 합이 홀수면 성원 win -> Yes, 짝수면 성원 lose -> No
# 그래프 이론
n = int(input())
# 2차원 인접 리스트 생성
arr = [[] for _ in range(n+1)]
for _ in range(n-1):
    a,b = map(int,input().split())
    arr[a].append(b)
    arr[b].append(a)

visited = [-1] * (n+1)
visited[1] = 0
stack = [1]
count = 0
value = [0] * (n+1) # 1과의 거리
# dfs
while stack:
    curr = stack.pop()
    if len(arr[curr]) == 1 and curr != 1:
        count += value[curr]
    else:
        for i in arr[curr]:
            # 방문하지 않았다면,
            if visited[i] == -1:
                stack.append(i)
                visited[i] = 0
                value[i] = value[curr] + 1
print("Yes" if count%2 == 1 else "No")