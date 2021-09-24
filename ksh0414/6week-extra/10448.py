triangle = [i*(i+1)//2 for i in range(1, 45)]
eureka = [0]*1001
for i in triangle:
    for j in triangle:
        for k in triangle:
            if i+j+k <= 1000:
                eureka[i+j+k] = 1

for _ in range(int(input())):
    print(eureka[int(input())])