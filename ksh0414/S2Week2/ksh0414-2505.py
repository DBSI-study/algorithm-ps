def check(c, index, init):
    global r, nums
    if c == 2:
        if nums == init:
            return True
        else:
            return False
    else:
        for step in range(1, len(index)):
            for i in range(0, len(index)-step):
                a, b = index[i]+1, index[i+step]
                switch(index, nums, i, i+step)
                if check(c+1, index, init):
                    r.append((a, b))
                    return True
                switch(index, nums, i, i+step)
                
def switch(index, arr, s_i, e_i):
    s, e = index[s_i], index[e_i]-1
    for i in range((e-s)//2+1):
        arr[s+i], arr[e-i] = arr[e-i], arr[s+i]
    dis = []
    for i in range(s_i+1, e_i+1):
        dis.append((index[i]-index[i-1]))
    dis = dis[::-1]
    for i in range(len(dis)):
        index[s_i+i+1] = index[s_i+i] + dis[i]
    

n = int(input())
nums = list(map(int, input().split()))
index = [0]

m = 1 if nums[1] - nums[0] > 0 else -1
for i in range(1, n-1):
    if nums[i]-nums[i-1] != m:
        if i - index[-1] == 2:
            index.append(i-1)
        index.append((i))
        m = 1 if nums[i+1] - nums[i] > 0 else -1
        
if nums[n-1]-nums[n-2] != nums[n-2]-nums[n-3]:
    index.append(n-1)
index.append(n-1)
index.append(n)
l = len(index)
r = []
if l == 2:
    if nums[1] - nums[0] > 0:
        r = [(1, 1), (1, 1)]
    else:
        r.append((1, n))
        r.append((1, 1))
if l == 3:
    if nums[1] - nums[0] > 0:
        r.append((index[1]+1, n))
    r.append((1, 1))
else:
    init = list(range(1, n+1))
    check(0, index, init)

print(*r[1])
print(*r[0])