import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    data = [0]*(n+1)
    for _ in range(n):
        a, b = map(int, input().split())
        data[a] = b
    lowest_grade = data[1]
    ans = 1
    for grade in data[2:]:
        if lowest_grade > grade:
            ans +=1
            lowest_grade = grade
    print(ans)