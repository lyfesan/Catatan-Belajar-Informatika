n = int(input())
maximum = 0

for x in range(n):
    num = int(input())
    if(x==0):
        maximum = num
    else:
        maximum = max(maximum, num)

print(maximum)