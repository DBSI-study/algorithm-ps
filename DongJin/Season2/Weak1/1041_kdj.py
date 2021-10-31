# 1041. 주사위 - 골드5
# a-f, c-d, b-e
# n이 1 일때, sum(a~f) - max(a~f)
# n이 2 이상 일때, 
# 3면 4개, 2면 (n-2)*4 + (n-1)*4 = 8n-12개, 1면 4*(n-2)*(n-1)+(n-2)*(n-2)개
# 1면 최솟값 : (n-2)*(n-2)*min
# 2면 최솟값 : (8n-12)*k
# k = min(a+min(b,c,d,e), b+min(c,d,f), c+min(e,f), d+min(e,f), e+f)
# 3면 최솟값 : 4*min(abc,abd,ade,aec,bcf,bdf,cef,def)

n = int(input())
a,b,c,d,e,f = map(int,input().split())
sum_dice = a+b+c+d+e+f
max_dice = max(a,b,c,d,e,f)
min_dice = min(a,b,c,d,e,f)
result = 0
if n == 1:
    result = sum_dice - max(a,b,c,d,e,f)
else:
    min_1 = (4*(n-2)*(n-1)+(n-2)*(n-2))*min_dice
    k = min(a+min(b,c,d,e), b+min(c,d,f), c+min(e,f), d+min(e,f), e+f)
    min_2 = (8*n-12)*k
    min_3 = 4*min(a+b+c,a+b+d,a+d+e,a+e+c,b+c+f,b+d+f,c+e+f,d+e+f)
    result = min_1 + min_2 + min_3
print(result) 