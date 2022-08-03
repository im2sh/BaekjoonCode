import sys

row, col = map(int,sys.stdin.readline().split())
miro = []
rowGuard = [False] * row
colGuard = [False] * col
rowCnt = 0
colCnt = 0

for i in range(row):
    miro.append(list(sys.stdin.readline().rstrip()))

for i in range(row):
    for j in range(col):
        if miro[i][j] == 'X':
            rowGuard[i] = True
            colGuard[j] = True

for i in rowGuard:
    if i == False:
        rowCnt+=1
for i in colGuard:
    if i == False:
        colCnt+=1

print(max(rowCnt,colCnt))
