# 1517. 버블소트 - 플레5
# 시간초과
n = int(input())
arr = list(map(int,input().split()))
sorted_arr = sorted(arr)
cnt = 0
# 가장 큰 수 부터 그 뒤에 자신보다 작은 것의 개수를 더함
for i in range(n-1,-1,-1):
    cnt += i - arr.index(sorted_arr[i])
    arr.remove(sorted_arr[i])
print(cnt)