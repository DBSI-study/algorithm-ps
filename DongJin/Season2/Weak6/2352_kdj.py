# 2352. 반도체 설계 - 골드2
# 오름차순으로 증가하는 가장 긴 수열의 원소 개수
# dp로 풀어버려따..
n = int(input())
ports = list(map(int,input().split()))
ports.insert(0,0)
dp = [1] * (n+1)
for i in range(n-1,0,-1):
    for j in range(i+1,n+1):
        if ports[i] < ports[j]:
            dp[ports[i]] = max(dp[ports[j]]+1,dp[ports[i]])

print(max(dp))