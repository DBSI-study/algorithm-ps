n = int(input('손님의 수를 입력해주세요: '))

while n > 100 :
    print("100명보다 많습니다. 다시 입력해주세요.")
    n = int(input())

SeJun_PC = list(map(int, input().split()))        
PC_place = [0] * 101          #PC방 자리
refused = 0                   #거절당한 사람

for i in SeJun_PC :
    if PC_place[i] != 0:
        refused += 1
    else:
        PC_place[i] += 1

print(str(refused) + "명이 거절됐습니다.")