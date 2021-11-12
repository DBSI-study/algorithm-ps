X, Y, P, Q = 0, 1, 2, 3

for _ in range(4):
    tmp = list(map(int, input().split()))
    forward = tuple(tmp[:4])
    backward = tuple(tmp[4:])
    if forward[X] > backward[X]:
        forward, backward = backward, forward
    
    sub_width = forward[P] - backward[X]
    hight_is_between = True
    if (forward[Y] <= backward[Y] <= forward[Q]):
        sub_hight = forward[Q] - backward[Y]
    elif(backward[Y] <= forward[Y] <= backward[Q]):
        sub_hight = backward[Q] - forward[Y]
    else:
        hight_is_between = False

    ans = None
    if not hight_is_between or sub_width < 0:
            ans = 'd'
    elif sub_hight*sub_width == 0:
        if sub_width > 0:
            ans = 'b'
        elif sub_hight > 0:
            ans = 'b'
        else:
            ans = 'c'
    else:
        ans = 'a'
    print(ans)