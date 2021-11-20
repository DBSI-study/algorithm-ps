# 1138. 한 줄로 서기 - 실버2
# 예시
# 입력 : 6 1 1 1 2 0 0
# 출력 : 6 2 3 4 7 5 1
n = int(input())
arr = list(map(int,input().split()))
arr = [0] + arr # index를 키에 맞추기 위함.
result = [0] * n
for i in range(1,len(arr)):
    cnt = arr[i]
    for j in range(arr[i],n): # arr[i] : i보다 왼쪽에 있는 사람 중 키가 큰 사람의 수
        if result[:j].count(0) < arr[i]:    # j앞까지 0의 개수가 arr[i] 보다 작아야 함.
            continue
        if result[j] == 0:
            result[j] = i
            break
print(*result)