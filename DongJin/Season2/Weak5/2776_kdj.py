# 2776. 암기왕 - 실버4
# 이진탐색 사용
def binary_search(target,arr):
    start = 0
    end = len(arr)-1
    while start <= end:
        mid = (start+end)//2
        if target == arr[mid]:
            return 1
        elif target < arr[mid]:
            end = mid - 1
        else:
            start = mid + 1
    return 0    
t = int(input())
for _ in range(t):
    n = int(input())
    book1 = list(map(int,input().split()))
    book1.sort()
    m = int(input())
    book2 = list(map(int,input().split()))
    for i in book2:
        print(binary_search(i,book1))
