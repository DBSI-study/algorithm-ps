# 16967. 배열 복원하기 - 실버3
# 배열은 무조건 겹침
h, w ,x ,y = map(int,input().split())
b = []
a = [[0] * w for _ in range(h) ]
for _ in range(h+x):
    b.append(list(map(int,input().split())))
# for i in a:
#     print(*i)
# print()
# for i in b:
#     print(*i)
for i in range(h):
    for j in range(w):
        if i >= x and j >= y:
            a[i][j] = b[i][j] - a[i-x][j-y]
        else:
            a[i][j] = b[i][j]
print()
for i in a:
    print(*i)