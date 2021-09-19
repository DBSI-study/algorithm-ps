from itertools import combinations

n, target = map(int, input().split())
nums = list(map(int, input().split()))
ans = 0
for num in combinations(nums, 3):
    tmp = sum(num)
    if tmp <= target:
        ans = max(ans, tmp)

print(ans)