from collections import defaultdict

def operate():
    global m, R, C, r, c
    tmp = []
    if m == 1:
        for i in range(R):
            line_cnt = counter(arr[i])
            line_cnt = sorted(line_cnt, key = lambda x:(x[1], x[0]))
            tmp.append(line_cnt)
        C = max([len(line) for line in tmp])*2
        result = [[0]*max(c, C) for _ in range(max(R, r))]
        for i in range(len(tmp)):
            for j in range(len(tmp[i])):
                result[i][j*2] = tmp[i][j][0]
                result[i][j*2+1] = tmp[i][j][1]
    else:
        for j in range(C):
            line_cnt = counter([arr[i][j] for i in range(R)])
            line_cnt = sorted(line_cnt, key = lambda x:(x[1], x[0]))
            tmp.append(line_cnt)
        R = max([len(line) for line in tmp])*2
        result = [[0]*max(c, C) for _ in range(max(R, r))]
        for j in range(len(tmp)):
            for i in range(len(tmp[j])):
                result[i*2][j] = tmp[j][i][0]
                result[i*2+1][j] = tmp[j][i][1]
    if R >= C:
        m = 1
    else:
        m = 0
    return result

def counter(arr):
    result = defaultdict(int)
    for x in arr:
        if x != 0:
            result[x] += 1
    return list(result.items())
    
         
r, c, k = map(int, input().split())
m = 1 #1:R, 0:C
arr = [[0]*max(3, c) for _ in range(max(3, r))]
for i in range(3):
    line = list(map(int, input().split()))
    for j in range(3):
        arr[i][j] = line[j]
    
time = 0
R = C = 3
while arr[r-1][c-1] != k and time <= 100:
    time += 1
    arr = operate()
print(time if time <= 100 else -1)