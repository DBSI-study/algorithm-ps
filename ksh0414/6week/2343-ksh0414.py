N, M = map(int, input().split())
data = list(map(int, input().split()))

start, end = max(data), sum(data)+1
ans = 0
while start < end:
    mid = (start+end)//2
    tmp = 1
    total = 0
    for x in data:
        if total+x > mid:
            total = x
            tmp += 1
            if tmp > M:
                break
        else:
            total += x
    if tmp > M:
        start = mid+1
    else:
        end = mid
        ans = mid
print(ans)