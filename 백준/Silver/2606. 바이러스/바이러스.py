import sys
from collections import deque


def bfs(graph, v, c):
    queue = deque([v])
    visited = [False] * (c + 1)
    visited[v] = True
    cnt = 0

    while queue:
        v = queue.popleft()

        for i in range(1,c+1):
            if visited[i] == False and graph[v][i] == 1:
                queue.append(i)
                visited[i] = True
                cnt += 1
    return cnt


c = int(sys.stdin.readline())
n = int(sys.stdin.readline())
cnt = 0

graph = [[0] * (c+1) for _ in range(c+1)]
visited = [False] * (c+1)
for i in range(n):
    x,y = map(int,sys.stdin.readline().split())
    graph[x][y] = 1
    graph[y][x] = 1

cnt = bfs(graph,1,c)
print(cnt)

