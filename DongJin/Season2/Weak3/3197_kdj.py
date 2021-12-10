# 3197. 백조의 호수 - 플레티넘 5
# 블로그 참고
from collections import deque
dx,dy = (0,1,0,-1), (1,0,-1,0)
# 백조가 서로 만나는지 확인하는 함수
def check():
    while sq:
        x,y = sq.popleft()
        if (x,y) == (x2,y2):
            return True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < r and 0 <= ny < c:
                if swan_arr[nx][ny] == 0:   # 백조가 방문 안했다면,
                    if arr[nx][ny] == "X":  # 방문할 곳이 빙하이면,
                        sq_temp.append((nx,ny)) # 다음 시간에 녹아 없어지므로 백조가 갈수 있기에 sq_temp에 임시 저장.
                    else:   # 방문할 곳이 물인데 아직 방문 안했다면,
                        sq.append((nx,ny))  # 백조가 이번 시간내에 방문할 수 있도록 sq에 저장.
                    swan_arr[nx][ny] = 1 # 미리 이동한 티 내줘야 이번 시간내에 중복이 일어나지 않는다.
    return False
# 시간이 지날 때마다 빙하가 녹게 하는 함수
def melt():
    while wq:
        x,y = wq.popleft()
        if arr[x][y] == "X":
            arr[x][y] = "." # 빙하가 왔으면 녹여준다.
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < r and 0 <= ny < c:
                if water_arr[nx][ny] == 0:  # 물인데 방문 안했거나, 빙하일 경우 탐색.
                    if arr[nx][ny] == "X": # 방문할 곳이 빙하이면
                        wq_temp.append((nx,ny)) # 다음 시간에 녹아 물이 되므로 wq_temp에 임시 저장.
                    else: # 방문할 곳이 물인데 아직 방문 안했다면,
                        wq.append((nx,ny))
                    water_arr[nx][ny] = 1 # 방문 했으므로 1로 변경.
r,c = map(int,input().split())
sq, sq_temp = deque(), deque()  # swan(백조)의 이동가능한 위치 저장
wq, wq_temp = deque(), deque()  # 물인 곳 저장.
arr = []    # 호수를 그대로 저장. 대신 백조(L)는 물(.)로 변경.
swan = []   # 백조 위치 저장
water_arr = [[0]*c for _ in range(r)] # 물 bfs시에 물일 때 1 저장. 이미 1이면 다음 시간에 굳이 방문 안하도록 설정 가능.
swan_arr = [[0]*c for _ in range(r)] # 백조의 방문 여부를 저장
for i in range(r):
    input_list = list(input().strip())
    arr.append(input_list)
    for j in range(c):
        if input_list[j] == "X":
            continue
        else:
            wq.append((i,j))
            water_arr[i][j] = 1
            if input_list[j] == "L":
                swan.append((i,j))
time = 0
(x1,y1),(x2,y2) = swan
sq.append((x1,y1))
swan_arr[x1][y1] = 1

while True:
    melt()
    if check():
        print(time)
        break
    time += 1
    wq, sq = wq_temp, sq_temp
    wq_temp, sq_temp = deque(), deque()