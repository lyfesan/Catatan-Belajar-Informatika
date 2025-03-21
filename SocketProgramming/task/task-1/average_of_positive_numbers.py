n = int(input())
avg = float(0.0)
positive = 0

for x in range(n):
    num = float(input())
    if(num > 0.0):
        positive+=1
        avg+=num

if positive > 0:
    # avg/=float(positive)
    print(f"{(avg/float(positive)):.2f}")
else:
    print("No positive numbers")