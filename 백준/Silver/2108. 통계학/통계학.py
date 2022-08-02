import sys
import math
from collections import Counter


n = int(sys.stdin.readline())

arr = []
result = []
sum = 0
for i in range(n):
    arr.append(int(sys.stdin.readline()))
    sum += arr[i]



arr.sort()
result.append(round(sum / n))
result.append(arr[n//2])
cnt = Counter(arr).most_common()

if len(arr) == 1:
    result.append(arr[0])
elif cnt[0][1] == cnt[1][1]:
    result.append(cnt[1][0])
else:
    result.append(cnt[0][0])

result.append(abs(arr[-1] - arr[0]))
for i in range(4):
    print(result[i])


