import sys

n = int(sys.stdin.readline())

for i in range(n):
    f = int(sys.stdin.readline())
    ho = int(sys.stdin.readline())

    floor = [i for i in range(1,ho+1)]

    for j in range(f):
        for k in range(1,ho):
            floor[k] += floor[k-1]
    print(floor[-1])