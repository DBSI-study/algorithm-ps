# 1958. LCS 3 - 골드3
# 줫같은 문제.
str1 = input()
str2 = input()
str3 = input()
n,m,l = len(str1), len(str2), len(str3)
# dp[i][j][k] : str1의 i번째, str2의 j번째, str3의 k번째까지의 문자열에서의 lcs
dp = [[[0 for _ in range(l+1)] for _ in range(m+1)] for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        for k in range(1,l+1):
            # 이전의 문자들이 서로 같다면, dp += 1
            if str1[i-1] == str2[j-1] == str3[k-1]:
                dp[i][j][k] = dp[i-1][j-1][k-1] + 1 #  dp[0][0][0] 은 의미 없지만 계산을 위해 존재
            # 셋 중 다른 게 있다면, 지금까지 탐색한 값 중 max값 저장
            else:
                dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1])
print(dp[n][m][l])