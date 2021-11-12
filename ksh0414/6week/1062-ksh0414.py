from itertools import combinations
a = ord('a')
alpha_to_bit = {chr(i+a):(1<<i) for i in range(26)}

n, k = map(int, input().split())
base = set('antatica')
k -= 5
ans = 0
if k < 0:
    print(0)
    exit(0)
elif k==26:
    print(n)
    exit(0)
else:
    words = []
    need_char = set()
    ans = 0
    for _ in range(n):
        word = set(input())-base
        l = len(word)
        if l == 0:
            ans += 1
        elif l <= k:
            need_char.update(word)
            tmp = 0
            for char in word:
                tmp += alpha_to_bit[char]
            words.append(tmp)
    
    max_need = 0
    for case in combinations([alpha_to_bit[x] for x in need_char], min(k, len(need_char))):
        sum_case = sum(case)
        tmp = 0
        for word in words:
            if word&sum_case == word:
                tmp+= 1
        max_need = max(max_need, tmp)
    ans += max_need
print(ans)