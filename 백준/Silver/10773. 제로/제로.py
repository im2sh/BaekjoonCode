import sys

n = int(sys.stdin.readline())
result = 0
lst = []
for i in range(n):
    x = int(sys.stdin.readline())
    if x == 0:
        lst.pop()
    else:
        lst.append(x)

for i in lst:
    result += i

print(result)