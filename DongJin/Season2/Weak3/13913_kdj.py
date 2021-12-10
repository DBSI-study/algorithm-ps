# 13913. 숨바꼭질 4 - 골드 4
# bfs 사용 - 블로그 참고
from collections import deque
n,k = map(int,input().split())
time = [0] * 100001     # 현재위치까지 왔을 때 걸린 시간을 기록
move = [0] * 100001     # 이전 위치를 기록
q = deque([n])
if n >= k:
    print(n-k)
    for i in range(n,k-1,-1):
        print(i,end = " ")
else:
    while q:
        x = q.popleft()
        if x == k:
            temp = []
            temp_x = x
            print(time[x])
            for _ in range(time[x]+1):
                temp.append(temp_x)
                temp_x = move[temp_x]
            print(" ".join(map(str,temp[::-1])))
            break
        for i in (x-1,x+1,2*x):
            if 0 <= i <= 100000 and time[i] == 0:
                move[i] = x
                time[i] = time[x] + 1
                q.append(i)