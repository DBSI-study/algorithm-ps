# 1715. 카드 정렬하기 - 골드4
# 우선순위 큐. heqpq사용
import heapq
n = int(input())
decks = []
for i in range(n):
    heapq.heappush(decks,int(input()))
cnt = 0
if n == 1:
    print(0)
else:
    for i in range(n-1):
        temp = heapq.heappop(decks)
        temp2 = temp + heapq.heappop(decks)
        cnt += temp2
        heapq.heappush(decks,temp2)
    print(cnt)