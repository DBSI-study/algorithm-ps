a, b = map(int, input().split())
nums = {}
cnt = 0
while a not in nums:
    nums[a] = cnt
    cnt += 1
    tmp = 0
    while a > 0:
        tmp += (a%10)**b
        a //= 10
    a = tmp
print(nums[a])