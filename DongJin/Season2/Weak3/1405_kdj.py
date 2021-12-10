# 1405. 미친 로봇 - 골드 5
# dfs 재귀 이용 -> pypy로 하니 성공! 그냥 돌리면 시간초과..
k,e,w,s,n = map(int,input().split())
dx = [1,-1,0,0]
dy = [0,0,1,-1]
p_list = [e,w,s,n]
result = 0
def dfs(x,y,visited,p,cnt):
    global result
    if cnt == k:
        result += p
        return
    for i in range(4):
        if p_list[i] == 0:
            continue
        nx = x+dx[i]
        ny = y+dy[i]
        np = p*p_list[i]/100
        if (nx,ny) not in visited:
            visited.append((nx,ny))
            dfs(nx,ny,visited,np,cnt+1)
            visited.pop()
dfs(0,0,[(0,0)],1,0)
print(result)  