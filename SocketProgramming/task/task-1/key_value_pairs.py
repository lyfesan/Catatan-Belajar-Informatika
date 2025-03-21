n = int(input())
pairs = {}

for i in range(n):
    key, value = input().split()
    pairs[key] = int(value)

q = input()

print(pairs[q])
