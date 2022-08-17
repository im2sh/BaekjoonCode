import sys
from collections import deque

n,m,v = map(int,sys.stdin.readline().split())

dfs_visited = [False] * (n+1)
bfs_visited = [False] * (n+1)

graph = [[0] * (n+1) for _ in range(n+1)]

for i in range(m):
    x,y = map(int,sys.stdin.readline().split())
    graph[x][y] = 1
    graph[y][x] = 1

def dfs(graph, v, visited, n):
    visited[v] = True
    print(v,end =' ')

    for i in range(1,n+1):
        if not visited[i] and graph[v][i]:
            dfs(graph,i,visited, n)

def bfs(graph, start, visited, n):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v, end = ' ')
        for i in range(1,n+1):
            if not visited[i] and graph[v][i]:
                queue.append(i)
                visited[i] = True

dfs(graph,v,dfs_visited, n)
print()
bfs(graph,v,bfs_visited, n)
