# 1937. 욕심쟁이 판다 - 골드3
def findValue(x, y):
    # cnt : 상하좌우에 자신 보다 큰 값의 개수
    cnt = 0
    for dx,dy in d:
        nx = x + dx
        ny = y + dy
        if 0 <= nx < n and 0 <= ny < n and forest[x][y] < forest[nx][ny]:
            dp[x][y] = max(dp[x][y],dp[x+dx][y+dy] + 1)
            cnt += 1
    # 주위에서 가장 클 때,
    if cnt == 0:
        dp[x][y] = 1
n = int(input())
forest = []
d = [(0,1),(1,0),(0,-1),(-1,0)]
# dp[x,y] : x,y좌표에서 시작했을 때 이동할 수 있는 칸의 최댓값
dp = [[0] * n for _ in range(n)]

# location에 좌표 저장
location = [[] for _ in range(1000001)]
for i in range(n):
    temp = list(map(int,input().split()))
    forest.append(temp)
    for j in range(n):
        location[temp[j]].append((i,j))
max_value = max(map(max,forest))
# dp 계산
for i in range(max_value,0,-1):
    if len(location[i]) == 0:
        continue
    else:
        for x,y in location[i]:
            findValue(x,y)
print(max(map(max,dp)))