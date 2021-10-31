# 11000. 강의실 배정 - 골드5
# 시간초과... => input = sys.stdin.readline 했더니 성공!
import heapq
import sys

input = sys.stdin.readline
n = int(input())
time = []
for i in range(n):
    s, t = map(int,input().split())
    time.append((s,t))
time.sort()
cls = []
heapq.heappush(cls,time[0][1])
for i in range(1,n):
    # 이전 수업의 종료시간이 현재 수업의 시작시간보다 작거나 같을 경우, 수업을 이어서 한다.
    # cls[0]을 pop하고 현재 수업의 종료시간을 push.
    if cls[0] <= time[i][0]:
        heapq.heapreplace(cls,time[i][1])    # heapreplace : heap에서 가장 작은 항목을 팝하고 반환하며, 새로운 item도 푸시한다.
    # 이전 수업의 종료시간이 현재 수업의 시작시간보다 클 경우, 새로운 강의실 추가
    # 현재 수업의 종료시간 push
    else:
        heapq.heappush(cls,time[i][1])
print(len(cls))