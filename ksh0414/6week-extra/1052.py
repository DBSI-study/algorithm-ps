#비트마스킹... 연습하자

n, k = map(int, input().split())

ans = 0
while bin(n).count('1') > k:
    plus = 2**(bin(n)[::-1].index('1'))
    ans += plus
    n += plus
print(ans)