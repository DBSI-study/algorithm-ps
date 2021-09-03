import sys
from collections import deque
input = sys.stdin.readline

def play(x, type, mode, board):
    s, e, m = mode
    if type == 'width':#가로
        b = []
        for i in range(n):
            stk = deque([0])
            for j in range(s, e, m):
                if stk[-1]*board[i][j] == 0: #둘 중 하나가 0이라면
                    stk[-1] += board[i][j]
                elif stk[-1] == board[i][j]:
                    stk[-1] *= 2
                    stk.append(0)
                else:
                    stk.append(board[i][j])
            for _ in range(n-len(stk)):
                stk.append(0)
            if m == 1:
                b.append(list(stk))
            else:
                b.append(list(stk)[::-1])
    else:#세로
        b = [[0] * n for _ in range(n)]
        for j in range(n):
            stk = deque([0])
            for i in range(s, e, m):
                if stk[-1]*board[i][j] == 0: #둘 중 하나가 0이라면
                    stk[-1] += board[i][j]
                elif stk[-1] == board[i][j]:
                    stk[-1] *= 2
                    stk.append(0)
                else:
                    stk.append(board[i][j])
            for _ in range(n-len(stk)):
                stk.append(0)
            for i in range(s, e, m):
                b[i][j] = stk.pop()
    return b

def dfs(board, x):
    if x == 5:
        global ans
        for line in board:
            ans = max(ans, max(line))
        return
    for t in type: 
        for m in mode:
            next_board = play(x+1, t, m, board)
            dfs(next_board, x+1)

n = int(input())
type = ('width', 'length') #가로, 세로
mode = ((n-1, -1, -1), (0, n, 1)) #감소 증가
board = []
ans = 0
for _ in range(n):
    board.append(list(map(int, input().split())))

dfs(board, 0)
print(ans)