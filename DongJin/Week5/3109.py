# 3109. 빵집 - 골드2 / 두번째 시도
# 재귀로 시도..성공!
def installPipeline(x,y):
    if y == c-1:
        return True
    for i in range(-1,2,1):
        if 0 <= x+i < r and 0 <= y+1 < c:
            if visited[x+i][y+1] == False:
                visited[x+i][y+1] = True
                if installPipeline(x+i,y+1) == True:
                    return True
    return False

r,c = map(int,input().split())
visited = [[False] * c for _ in range(r)]
for i in range(r):
    temp = input()
    for j in range(c):
        if temp[j] == "x":
            visited[i][j] = True
count = 0
for i in range(r):
    if installPipeline(i,0):
        count += 1
print(count)