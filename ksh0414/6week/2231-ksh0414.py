n = int(input())

def solve():
    for x in range(1, n+1):
        tmp = x
        for i in str(x):
            tmp += int(i)
        if tmp == n:
            return x
    return 0

print(solve())