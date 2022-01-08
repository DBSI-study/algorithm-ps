# 1744. 수 묶기 - 골드4
def sum_arr(arr,check):
    k = len(arr)
    result = 0
    for i in range(0,k-1,2):
        result += arr[i]*arr[i+1]
    if k%2 == 1:    # 개수가 홀수 일땐, 마지막 한 수를 더해줘야함.
        if zero == 0 or check:  # check : 0(-), 1(+)
            result += arr[k-1]
    return result
    
n = int(input())
minus = []
plus = []
zero = 0
one = 0     # 1은 x와의 곱셈보다 더할때 수가 커지므로 따로 처리.
for i in range(n):
    num = int(input())
    if num == 1:
        one += 1
        continue
    if num > 0:
        plus.append(num)
    elif num < 0:
        minus.append(num)
    else:
        zero += 1
minus.sort()
plus.sort(reverse=True)
result = sum_arr(minus,0) + sum_arr(plus,1) + one
print(result)
