INF = int(1e3)

order = list(map(int, input().split()))
order.pop()
order = [0]+order

N = len(order)
if N==1:
    print(0)
    exit(0)
    
dp = [[[INF]*5 for _ in range(5)] for _ in range(N)]
last = order[1]
dp[0][0][0] = 0
dp[1][last][0] = 2
for i in range(2, N):
    now = order[i]
    for j in range(5):
        if last == now and j != now:
            dp[i][last][j] = min(dp[i][last][j], dp[i-1][last][j]+1)
            dp[i][j][last] = min(dp[i][j][last], dp[i-1][j][last]+1)
        elif j == now:
            dp[i][last][j] = min(dp[i][last][j], dp[i-1][last][j]+1)
            dp[i][j][last] = min(dp[i][j][last], dp[i-1][j][last]+1)
        else:
            sub_l = abs(last-now)
            sub_j = abs(j-now)
            if sub_l%2 == 0:     l_plus = 4
            else:                l_plus = 3

            if j == 0:           j_plus = 2
            elif sub_j%2 == 0:   j_plus = 4
            else:                j_plus = 3
            
            dp[i][now][j] = min(dp[i][now][j], dp[i-1][last][j]+l_plus)
            dp[i][last][now] = min(dp[i][last][now], dp[i-1][last][j]+j_plus)
            dp[i][now][last] = min(dp[i][now][last], dp[i-1][j][last]+j_plus)
            dp[i][j][now] = min(dp[i][j][now], dp[i-1][j][last]+l_plus)
    last = now

ans = INF
for i in range(5):
    for j in range(5):
        ans = min(ans, dp[N-1][i][j])
print(ans)