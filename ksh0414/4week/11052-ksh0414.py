n = int(input())
prices = list(map(int, input().split()))
dp = [0] * (n+1)
dp[1] = prices[0]#1장

for i in range(2, n+1):#2장부터 n장까지
    pre_dp = [dp[j] + dp[i-j] for j in range(1, (i//2)+1)]
    pre_dp.append(prices[i-1])
    dp[i] = max(pre_dp)
print(dp[n])