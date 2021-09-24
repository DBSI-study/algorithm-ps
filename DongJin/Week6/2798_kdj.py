# 2798. 블랙잭 - 브론즈2
def solve():
    result = 0
    for i in range(n-2):
        for j in range(i+1,n-1):
            for k in range(j+1,n):
                temp = cards[i] + cards[j] + cards[k]
                if temp == m:
                    return temp
                if temp <= m and abs(temp - m) < abs(result-m):
                    result = temp
    return result
n, m = map(int,input().split())
cards = list(map(int,input().split()))
cards.sort()
print(solve())