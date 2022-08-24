from dis import findlabels
import sys

n = int(sys.stdin.readline())
card = []
find = []
result = []


card = list(map(int,sys.stdin.readline().split()))

m = int(sys.stdin.readline())

find = list(map(int,sys.stdin.readline().split()))


result = {}

for i in card:
    if i in result:
        result[i] += 1
    else:
        result[i] = 1
    
for i in find:
    cnt = result.get(i)
    if cnt == None:
        print(0, end =' ')
    else:
        print(cnt, end = ' ')