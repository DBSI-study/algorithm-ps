# 2470. 두 용액 - 골드5
# 두 포인터 사용
# 기준값을 초기에 설정을 잘못해서 틀렸었다.
n = int(input())
arr = list(map(int,input().split()))
arr.sort()
left = 0
right = n-1
result = 2e9+1
ans1,ans2 = 0,0
while left < right:
    mix = arr[left] + arr[right]
    # print("arr[left]:",arr[left],", arr[right]:",arr[right],", mix:",mix)
    if abs(mix) < result:
        result = abs(mix)
        ans1, ans2 = arr[left], arr[right]
    if mix == 0:
        break
    elif mix > 0:
        right -= 1
    else:
        left += 1
print(ans1,ans2)