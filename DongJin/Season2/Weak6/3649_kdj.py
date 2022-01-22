# 3649. 로봇 프로젝트 - 골드4
# 두 포인터
# 정렬 후 두 블록 합이 구멍보다 크면 right - 1, 작으면 left + 1
while True:
    try:
        x = int(input())*int(1e7)
        n = int(input())
        legos = []
        for _ in range(n):
            block = int(input())
            if block <= x:
                legos.append(block)
        legos.sort()
        ans = "danger"
        left = 0
        right = len(legos) - 1
        while left < right:
            if legos[left] + legos[right] == x:
                ans = "yes {} {}".format(legos[left],legos[right])
                break
            elif legos[left] + legos[right] < x:
                left += 1
            else:
                right -= 1
        print(ans)
    except:
        break