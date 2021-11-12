n = int(input())
if n%5 == 0:
    print(n//5)
else:
    ans = 0
    for i, x in enumerate(range(n, 0, -5)):
        if x%3 != 0:
            continue
        ans = i + x//3
    print(ans if ans != 0 else -1)