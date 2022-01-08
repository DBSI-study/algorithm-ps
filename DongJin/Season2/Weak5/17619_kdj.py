# 17619. 개구리 점프 - 골드2
# 부분성공 - 19점
def jump(s,e):
    global cut
    start_idx, end_idx = -1, -1
    for i in range(len(arr)):
        if arr[i][3] == s:
            start_idx = i
        elif arr[i][3] == e:
            end_idx = i
        if start_idx != -1 and end_idx != -1:
            break 
    if start_idx > end_idx:
        start_idx, end_idx = end_idx, start_idx
    # start_idx와 end_idx 사이의 값이 cut 안에 들어 있으면 return 0
    for i in cut:
        if start_idx <= i < end_idx:
            return 0
    for i in range(start_idx,end_idx):
        if arr[i][1] < arr[i+1][0]: # 다음 구간과 겹치지 않으면 return 0
            cut.append(i)
            return 0
    return 1
n,q = map(int,input().split())
arr = []  # (순서,x1,x2,y)
for i in range(1,n+1):
    x1,x2,y = map(int,input().split())
    arr.append((x1,x2,y,i))
arr.sort()
#print(*arr)
cut = []
for _ in range(q):
    start,end = map(int,input().split())
    print(jump(start,end))
    #print(cut)