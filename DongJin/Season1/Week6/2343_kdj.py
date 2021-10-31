# 2343. 기타 레슨 - 실버1
# 이분탐색
def binarySearch(left,right):
    result = size
    while left <= right:
        mid = (left + right) // 2
        if mid < max(lesson_list):
            left = mid + 1
            continue
        count = 0
        temp = 0
        for i in range(n):
            temp += lesson_list[i]
            if temp > mid:
                temp = lesson_list[i]
                count += 1
        if count < m:   # 가능한 경우
            right = mid - 1
            result = min(mid,result)
        else:
            left = mid + 1
        #print(count, left, right,mid)
    return result
n, m = map(int,input().split())
lesson_list = list(map(int,input().split()))
size = sum(lesson_list)
#print(size)
print(binarySearch(size//m,size))