# 11054. 가장 긴 바이토닉 부분 수열 - 골드3
n = int(input())
arr = list(map(int,input().split()))
dp = [[0,0] for _ in range(n)]
# arr[i]를 가장 큰 수로 두었을 때,
# dp[i][0] : 왼쪽의 가장 긴 증가하는 수열의 원소 수
# dp[i][1] : 오른쪽에서 가장 긴 감소하는 수열의 원소 수
for i in range(1,n):
    for j in range(i-1,-1,-1):
        if arr[i] > arr[j]:
            dp[i][0] = max(dp[i][0],dp[j][0]+1)

for i in range(n-2,-1,-1):
    for j in range(i+1,n):
        if arr[i] > arr[j]:
            dp[i][1] = max(dp[i][1],dp[j][1]+1)
ans = 0
for a,b in dp:
    ans = max(ans,a+b)
print(ans+1)    # 자기 자신도 개수에 포함