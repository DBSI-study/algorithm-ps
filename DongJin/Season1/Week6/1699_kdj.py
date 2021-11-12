# 1699. 제곱수의 합 - 실버3
# python3로 하면 시간초과..pypy로 하니 정답!
n = int(input())
dp = [i for i in range(n+1)]
for i in range(1,n+1):
    for j in range(int(i**0.5),0,-1):
        dp[i] = min(dp[i], 1 + dp[i-j*j])
print(dp[n])