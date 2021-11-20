# 17140. 이차원 배열과 연산 - 골드4
# 배열 회전에 zip()사용, 함수로 만들기 => 성공! 애초에 while 조건에서 indexError가 난 거였다.

# A[r][c]가 k값이 나올 때 까지 연산을 수행하는데, 연산을 진행하다보면 
# 배열 A의 크기가 변하면서 A[r][c]에 해당하는 원소가 없어 IndexError가 발생할 수 있다.
# → 예외처리 필요
from collections import Counter
r,c,k = map(int,input().split())
a = [list(map(int,input().split())) for _ in range(3)]
t = 0
len_row = 3
len_col = 3
r -= 1
c -= 1
while 1:
    # 조건에 맞으면 중단.
    if len(a) > r and len(a[0]) > c:
        if a[r][c] == k :
            break
    t += 1
    if t > 100:
        t = -1
        break
    if len_row < len_col:
        a = list(map(list,zip(*a)))
        x, y = len_col, len_row
    else : 
        x, y = len_row, len_col
    for i in range(x):
        count_0 = a[i].count(0)
        for _ in range(count_0):
            a[i].remove(0)
        a[i].sort()
        temp = sorted(Counter(a[i]).most_common(), key=lambda k : k[1])
        a[i].clear()
        for j in range(len(temp)):
            a[i].append(temp[j][0])
            a[i].append(temp[j][1])
        if len(a[i]) > 100:     # 크기가 100이 넘어가면 슬라이싱
            a[i] = a[i][:100]
        y = max(y, len(a[i]))
    for i in range(x):
        if len(a[i]) < y:
            a[i] += [0]*(y-len(a[i]))
    if len_row < len_col :
        a = list(map(list,zip(*a)))
        len_row = y
        len_col = x
    else:
        len_row = x
        len_col = y
    # print(t)
    # for i in a:
    #     print(*i)
    # print()
print(t)