import sys

n = int(sys.stdin.readline())

list = []

for i in range(n):
    age, name = sys.stdin.readline().rstrip().split()
    age = int(age)
    list.append((age,name))

list.sort(key = lambda x : x[0])

for i in list:
    print(i[0],i[1])
