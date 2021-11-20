# 2505. 두 번 뒤집기 - 플레5
# 구간 [i,j] 사이 뒤집기 : arr[i-1:j] = arr[i-1:j][::-1]
# 뒤집기할 때 증가구간, 감소구간인지 파악하고 뒤집자..
# 어렵다...실패!
from itertools import combinations
import copy

def solve():
    if len(change_section) == 1:
        if arr[0] == 1:
            print(1,1)
            print(1,1)
            return
        else:
            print(1,n)
            print(1,1)
            return
    else:
        sections = list(combinations(change_section,2))
        print(sections)
        for i,j in sections:
            if j - i == 1:
                continue
            temp = copy.deepcopy(arr)   # 내부의 객체들까지 모두 새롭게 copy
            temp[i:j] = temp[i:j][::-1] # 구간 뒤집기
            print("[{},{}] :".format(i+1,j),temp)
            if temp[0] != 1:
                change_section2 = [0]
            else:
                change_section2 = [n]
            for k in range(1,len(temp)):
                if abs(temp[k]- temp[k-1]) != 1:
                    change_section2.append(k)
            cnt = len(change_section2)
            change_section2.sort()
            if cnt <= 3:
                x1, y1 = i+1, j
                print(x1,y1)
                break
        print(change_section2)
        if cnt <= 3:
            if cnt == 1:    # 이미 초기상태일 때,
                if temp[0] == 1:
                    print(1,1)
            
            elif cnt == 2:
                if temp[0] == 1:
                    print(change_section2[1]+1,n)
                else:
                    print(1,change_section2[1])
            else:
                if change_section2[0] == 1:
                    print(change_section2[1]+1, change_section2[2])
                else:
                    print(change_section2[0]+1, change_section2[1]) 

n = int(input())
arr = list(map(int,input().split()))
if arr[0] != 1:
    change_section = [0]
else:
    change_section = [n]
for i in range(1,len(arr)):
    if abs(arr[i]- arr[i-1]) != 1:
        change_section.append(i)
change_section.sort()
print(change_section)
solve()
