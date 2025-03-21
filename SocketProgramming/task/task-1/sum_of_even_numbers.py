n = int(input())
sum = 0

for x in range(n):
    num = int(input())
    if num % 2 == 0:
        sum += num

print(sum)