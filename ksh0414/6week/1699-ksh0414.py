x = int(input())
dp = [0 for _ in range(x+1)]
dp[1] = 1

for i in range(2, x+1):
    dp[i] = dp[i-1]+1
    for j in range(2, int(x**0.5)+1):
        if i-j**2 >= 0:
            dp[i] = min(dp[i], dp[i-j**2]+1)
        else:
            break
print(dp[x])
