import sys

n, m = map(int,sys.stdin.readline().split())
tree = list(map(int,sys.stdin.readline().split()))

tree.sort()

s = 0
e = tree[-1]

while s <= e:
    mid = (s+e)//2
    sum = 0
    for i in tree:
        if i > mid:
            sum += i - mid
    
    if m <= sum:
        s = mid + 1
    else: 
        e = mid - 1

print(e)