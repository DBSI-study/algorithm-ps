# 10815. 숫자카드 - 실버4
def bs(target,arr):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = (left+right)//2
        if arr[mid] == target:
            return 1
        elif arr[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return 0
n = int(input())
cards = list(map(int,input().split()))
cards.sort()
m = int(input())
check = list(map(int,input().split()))
for i in check:
    print(bs(i,cards), end=" ")