# 1449. 수리공 항승 - 실버3
n,l = map(int,input().split())
arr = list(map(int,input().split()))
arr.sort()
cnt = 0 # 필요한 테이프 개수
temp = 0
for i in range(n):
    if i == n-1:
        cnt += 1
    else:    
        temp += arr[i+1] - arr[i]
        if temp >= l:
            cnt += 1
            temp = 0
print(cnt)