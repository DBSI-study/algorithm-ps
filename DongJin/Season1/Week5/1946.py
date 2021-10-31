# 1946. 신입 사원 - 실버1
def selection(grades, n):
    temp = grades[0][1] # 첫 temp : 서류심사 1등의 면접 순위
    count = 1 # 1등은 무조건 선발
    for i in range(1,n):
        if temp > grades[i][1]: # temp보다 다음 사람의 면접 순위가 낮아야 선발
            temp = grades[i][1] # temp 업데이트
            count += 1
    print(count)
t = int(input())

for _ in range(t):
    n = int(input())
    ranking = []
    for _ in range(n):
        ranking.append(tuple(map(int,input().split())))
    ranking.sort()  # 서류 심사 순위를 기준으로 정렬
    selection(ranking, n)