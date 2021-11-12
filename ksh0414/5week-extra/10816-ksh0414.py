#이진탐색 < defaultdict < Counter
from collections import Counter

n = int(input())
card_list = list(map(int, input().split()))
counter = Counter(card_list)
m = int(input())

for target in map(int, input().split()):
    print(counter[target], end = ' ')