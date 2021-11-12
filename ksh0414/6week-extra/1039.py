from collections import deque

n, k = input().split()
l = len(n)
k = int(k)

def same_num_check(arr):
    nums = []
    for x in arr:
        if x in nums:
            return True
        nums.append(x)
    return False

if l < 2 or n[1:] == '0':#swap을 할 수 없는 경우
    ans = -1

else:#할 수 있는 경우
    result = [int(x) for x in n]#str형을 int형으로 변경
    q = deque([(result, k, 0)])#최선의 케이스를 구하기 위한 q
    same_num_in_result = False #같은 숫자가 있는지 확인하기 위해

    while q:#각 경우에 대하여 check
        tmp, count, start_idx = q.popleft()
        tmp = list(tmp)#swap을 위해 tuple형의 tmp를 list형으로
        if tmp > result:#만약 result가 작다면
            k = count #그 케이스의 k값(남은 swap횟수)를 저장
            result = tmp #그 케이스의 result를 저장
        if count <= 0 or start_idx >= l-1: #더이상 swap을 할 수 없다면
            continue #continue

        for i in range(start_idx, l-1): #앞에서부터 swap할 수 있는 경우를 탐색
            max_value = tmp[i]
            max_idx = i
            same_idx = [l-1]
            for j in range(i+1, l): #순차적으로 탐색
                if max_value < tmp[j]:
                    max_value = tmp[j]
                    same_idx = [j]
                    max_idx = j
                elif max_value == tmp[j]: #같은 숫자가 있다면
                    same_idx.append(j)

            if max_idx != i: #i뒤에 더 큰 수가 있을 때만
                for idx in same_idx:#각 숫자에 대한 case를 조사
                    tmp[i], tmp[idx] = tmp[idx], tmp[i]
                    q.append((tuple(tmp), count-1, i+1))
                    tmp[i], tmp[idx] = tmp[idx], tmp[i]
                break
            
    #k > 0이면 result는 정렬된 상태, k==0이면 result를 출력
    if not same_num_check(result) and k%2: #안에 같은 숫자가 없고 나머지 횟수가 홀수라면
        result[-1], result[-2] = result[-2], result[-1] #맨 뒤의 두 숫자를 교환
    ans = "".join([str(x) for x in result]) #같은 숫자가 있거나 나머지 횟수가 짝수라면 교환x

print(ans)