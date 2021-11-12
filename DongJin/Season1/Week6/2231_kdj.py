# 2231. 분해합 - 브론즈2
def findConstructor(N):
  for i in range(1, N+1):
    temp = i
    for j in str(i):
      temp += int(j)
    if temp == N:
       print(i)
       break
    if i == N:
      print(0)
      
n = int(input()) 
findConstructor(n)