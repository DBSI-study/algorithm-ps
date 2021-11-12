import sys
import copy
input = sys.stdin.readline

def play(x, type, mode, b):
    s, e, m = mode
    board = copy.deepcopy(b)
    if type == 'width':#가로
        for i in range(n):
            ps, pe = s, s+m
            while ps != e:
                pe = ps+m
                while 0 <= pe+m < n and board[i][pe] == 0:
                    pe += m
                if board[i][pe] == 0: #뒤에 더이상 수가 없는 경우
                    break 
                #pe가 숫자인 경우
                if board[i][ps] == 0: #ps가 0인 경우
                    #pe의 숫자를 앞으로 당김
                    board[i][ps], board[i][pe] = board[i][pe], board[i][ps]
                else: #ps가 숫자일 경우
                    if board[i][ps] == board[i][pe]: #같은경우
                        #둘을 합침, ps는 확정
                        board[i][ps] *= 2
                        board[i][pe] = 0
                        ps += m
                    else:
                        ps += m #그 뒤로 당김
                        board[i][ps], board[i][pe] = board[i][pe], board[i][ps]
    else:#세로
        for j in range(n):
            ps, pe = s, s+m
            while ps != e:
                pe = ps+m
                while 0 <= pe+m < n and board[pe][j] == 0:
                    pe += m
                if board[pe][j] == 0: #뒤에 더이상 수가 없는 경우
                    break 
                #pe가 숫자인 경우
                if board[ps][j] == 0: #ps가 0인 경우
                    #pe의 숫자를 앞으로 당김
                    board[ps][j], board[pe][j] = board[pe][j], board[ps][j]
                else: #ps가 숫자일 경우
                    if board[ps][j] == board[pe][j]: #같은경우
                        #둘을 합침, ps는 확정
                        board[ps][j] *= 2
                        board[pe][j] = 0
                        ps += m
                    else:
                        ps += m #그 뒤로 당김
                        board[ps][j], board[pe][j] = board[pe][j], board[ps][j]
    return board

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
mode = ((n-1, 0, -1), (0, n-1, 1)) #감소 증가
board = []
ans = 0
for _ in range(n):
    board.append(list(map(int, input().split())))

dfs(board, 0)
print(ans)