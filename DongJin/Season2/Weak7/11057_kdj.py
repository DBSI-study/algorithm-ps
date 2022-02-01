# 11057. 오르막수 - 실버1
n = int(input())
# dp[n][c] : c*(10^n)이상의 n자리수 오르막 수의 개수 
dp = [[1]*10 for i in range(n+1)]   

for i in range(2,n+1):
    for j in range(10):
        dp[i][j] = sum(dp[i-1][j::])  # dp[i][j] : dp[i-1][j] ~ dp[i-1][9] 의 합
print(sum(dp[n])%10007)