# 1080. 행렬 - 실버2
# 배열의 맨 왼쪽 위부터 배열을 비교하며 값이 다른 경우 3x3으로 값 변경.
n,m = map(int,input().split())

a = [list(map(int,input())) for _ in range(n)]
b = [list(map(int,input())) for _ in range(n)]
cnt = 0

def changeMatrix3x3(x,y):
    for i in range(3):
        for j in range(3):
            a[x+i][y+j] = 1 - a[x+i][y+j]

for i in range(n-2):
    for j in range(m-2):
        if a[i][j] != b[i][j]:
            changeMatrix3x3(i,j)
            cnt += 1
check = False
for i in range(n):
    for j in range(m):
        if a[i][j] != b[i][j]:
            check = True;
            break
    if check:
        break

if check:
    print(-1)
else:
    print(cnt)