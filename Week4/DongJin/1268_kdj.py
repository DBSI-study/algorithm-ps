# 1268. 임시 반장 정하기 - 브론즈1
n = int(input())
same_class = [[] for _ in range(n+1)]    # index : 학생번호, element : 같은 반을 해봤던 학생들 번호
matrix = [[0,0,0,0,0]]
for _ in range(n):
    matrix.append(list(map(int,input().split())))
for i in range(1,n+1):
    for k in range(i+1,n+1):
        for j in range(0,5):
            # 반이 같다면 같은 반 학생이었던 학생의 번호를 same_class에 저장
            if matrix[i][j] == matrix[k][j]:
                if k not in same_class[i]: 
                    same_class[i].append(k)
                if i not in same_class[k]:
                    same_class[k].append(i)
# 임시 반장 정하기    
most_friendliest = 1 # 아무도 같은 반이었던 적이 없는 경우를 대비해 1번 학생으로 초기화
friends = 0
for i in range(1,n+1):
    if len(same_class[i]) > friends:
        most_friendliest = i
        friends = len(same_class[i])
print(most_friendliest)