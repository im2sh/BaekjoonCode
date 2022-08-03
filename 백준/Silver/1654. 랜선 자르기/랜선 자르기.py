import sys

k, n = map(int, sys.stdin.readline().split())

lst = []

for i in range(k):
    lst.append(int(sys.stdin.readline()))

lst.sort()

s = 1
e = max(lst)


while s <= e:
    mid = (s+e) // 2
    temp = 0

    for i in lst:
        temp += i//mid
    
    if n <= temp:
        s = mid + 1
    else:
        e = mid - 1

print(e)


