import sys
from collections import defaultdict
input = sys.stdin.readline

alpha_value = defaultdict(int)
for _ in range((int(input()))):
    alpha = input().strip()
    n = len(alpha)
    for i in range(n):
        alpha_value[alpha[n-i-1]] += 10**i
alpha_value = list(sorted(alpha_value.items(), key = lambda x: x[1], reverse = True))

ans = 0
for x in zip(range(9, -1, -1), alpha_value):
    ans += x[0] * x[1][1]
print(ans)