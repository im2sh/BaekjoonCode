from collections import deque
import sys

t = int(sys.stdin.readline())

dx = [-1,1,0,0]
dy = [0,0,-1,1]


def bfs(graph, x, y):
    queue = deque()
    queue.append((x,y))
    graph[x][y] = 0

    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if graph[nx][ny] == 0:
                continue
            if graph[nx][ny] == 1:
                graph[nx][ny] = 0
                queue.append((nx,ny))

for i in range(t):
    n,m,k = map(int,sys.stdin.readline().split())
    graph = [[0] * m for _ in range(n)]
    cnt = 0
    
    for i in range(k):
        x, y = map(int,sys.stdin.readline().split())
        graph[x][y] = 1
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1:
                bfs(graph,i,j)
                cnt+=1
    print(cnt)