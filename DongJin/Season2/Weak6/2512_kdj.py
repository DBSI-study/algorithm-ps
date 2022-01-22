# 2512. 예산 - 실버3
# 모든 예산총액이 예산요청 최솟값보다 작을 때를 고려해야함.
def solve(arr,total):
    left = 1
    right = total
    ans = left
    while left <= right:
        mid = (left+right)//2
        temp = [i if i <= mid else mid for i in arr]
        if sum(temp) == total:
            return mid
        elif sum(temp) < total:
            left = mid + 1
            ans = max(ans,mid)
        else:
            right = mid - 1
    return ans
n = int(input())
needs = list(map(int,input().split()))
m = int(input())
if sum(needs) > m:
    print(solve(needs,m))
    
else:
    print(max(needs))