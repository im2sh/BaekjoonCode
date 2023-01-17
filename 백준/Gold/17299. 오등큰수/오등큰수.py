import sys

n = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))
count = [0] * 1000001

for cnt in arr:
    count[cnt] += 1

stack = []
answer = [-1] * n
stack.append(0)

for i in range(0, n):
    while stack and count[arr[stack[-1]]] < count[arr[i]]:
        answer[stack.pop()] = arr[i]
    stack.append(i)

print(*answer) 