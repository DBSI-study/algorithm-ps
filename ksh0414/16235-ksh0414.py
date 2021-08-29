import sys
input = sys.stdin.readline
D = [(1,0), (0,1), (-1,0), (0,-1), (1,1), (-1,-1), (1,-1), (-1,1)]

n, m, k = map(int, input().split())
board = [[[5, 0] for _ in range(n)] for _ in range(n)]
data = []
trees = [[[[], []] for _ in range(n)] for _ in range(n)]
for _ in range(n):
    data.append(list(map(int, input().split())))
for _ in range(m):
    r, c, w = map(int, input().split())
    trees[r-1][c-1][0].append(w)

for year in range(1, k+1): #(year%2):다음해 ((year-1)%2):올해
    for i in range(n):
        for j in range(n):
            board[i][j][year%2] = 0 #해당 칸 초기화
            trees[i][j][(year-1)%2].sort(reverse=True)
            while trees[i][j][(year-1)%2]: #해당칸에 있는 나무들
                age = trees[i][j][(year-1)%2].pop()
                if board[i][j][(year-1)%2] >= age: #성장가능 / 봄
                    board[i][j][(year-1)%2] -= age#양분흡수
                    trees[i][j][year%2].append(age+1) #나무는 내년까지
                    if (age+1) % 5 == 0: #5의 배수 / 가을
                        for di, dj in D:
                            ni, nj = i+di, j+dj
                            if 0 <= ni < n and 0 <= nj < n:
                                trees[ni][nj][year%2].append(1)
                else: #성장불가 -> 여름에 양분
                    board[i][j][year%2] += age // 2
                    while trees[i][j][(year-1)%2]: #배열이 정렬되어있기 때문에 뒤에 나무는 전부 죽음 
                        board[i][j][year%2] += trees[i][j][(year-1)%2].pop() // 2 #일괄적으로 양분분배
                    break #해당 칸 종료
            board[i][j][year%2] += board[i][j][(year-1)%2] + data[i][j] #겨울

tree_count = 0
for i in range(n):
    for j in range(n):
        tree_count += len(trees[i][j][k%2])
print(tree_count)
