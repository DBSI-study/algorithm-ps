# 1339. 단어 수학 - 골드4
n = int(input())
# (A : 0) ~ (Z : 25)
arr = [0] * 26
for _ in range(n):
    temp = input()
    k = len(temp)
    for i in range(k):
        arr[ord(temp[i]) - 65] += pow(10, k-i-1)
# arr를 내림차순으로 정렬한 후 앞에서 부터 9~0까지 곱해서 더한다.
arr.sort(reverse=True)
sum_words = 0
for i in range(10):
    sum_words += arr[i] * (9-i)
print(sum_words)    