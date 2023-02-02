import sys

n = int(sys.stdin.readline())

lst = set(map(int,sys.stdin.readline().split()))

m = int(sys.stdin.readline())

findLst = list(map(int,sys.stdin.readline().split()))

for i in findLst:
    if i in lst:
        print("1")
    else:
        print("0")
    
