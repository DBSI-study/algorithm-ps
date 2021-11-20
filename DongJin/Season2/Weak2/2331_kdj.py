# 2331. 반복수열 - 실버 4
n, p = map(int,input().split())
d = [n]
i = 0
def nextNum(k):
    a = str(k)
    result = 0
    for i in a:
        result += pow(int(i),p)
    return result
while True:
    next = nextNum(d[i])
    # next가 d 안에 있다면, 반복되지 않은 수의 개수는 next값이 처음 나온 index와 같다.
    if next in d:
        print(d.index(next))
        break
    d.append(next)
    i += 1