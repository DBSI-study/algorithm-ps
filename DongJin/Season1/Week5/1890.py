# 1890. 점프 - 실버2
# 재귀 사용
def jump(x,y):
    if x == n-1 and y == n-1:
        return 1
    if result[x][y] == -1:
        result[x][y] = 0
        value = game[x][y]  # value : 점프할 값
        # r[0][0] = r[2][0] + r[0][2] = r[2][3] + (r[1][2] + r[0][3]) = 1 + r[1][4] + 1 = 1 + 1 + 1 = 3
        if 0 <= x + value < n and 0 <= y < n:
            result[x][y] += jump(x+value,y)
        if 0 <= x < n and 0 <= y + value < n:
            result[x][y] += jump(x,y+value)
    return result[x][y]
n = int(input())
game = []
result = [[-1] * n for _ in range(n)]
for _ in range(n):
    game.append(list(map(int,input().split())))
print(jump(0,0))