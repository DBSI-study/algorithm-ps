# 1453. 피시방 알바 - 브론즈1
n = int(input())
arr = [0] * 101
guest = list(map(int,input().split()))
for i in guest:
    arr[i] = 1
print(len(guest) - arr.count(1))