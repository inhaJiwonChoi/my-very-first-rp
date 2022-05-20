from sys import stdin
input = stdin.readline



v, e = map(int, input().split())



adj_list = [[] for i in range(v+1)] ### 주어지는 graph를 인접 리스트 방식으로 저장하기 위한 list
adj_list_t = [[] for i in range(v+1)] ### 주어지는 graph의 transposed graph를 저장하기 위한 list
in_degree = [0 for i in range(v+1)] ### 각 vertex의 incoming degree를 저장하는 list
vertice_list_sorted = [i for i in range(1, v+1)] ### 각 vertex가 incoming degree에 따라 정렬될 list
visited = [False for i in range(v+1)] ### 각 vertex의 방문 여부를 저장하는 list
stack = [] ### 첫번째 dfs 수행 시 사용될 stack
stack_t = [] ### 두번째 dfs 수행 시 사용될 stack
scc = [0 for i in range(v+1)] ### 각 vertex마다 scc의 leader를 저장하는 list



### 입력받을 값을 인접 리스트 방식으로 저장; Transposed graph와 각 vertex의 incoming degree 저장
for i in range(e):
    start_vertex, end_vertex = map(int, input().split())
    adj_list[start_vertex].append(end_vertex)
    adj_list_t[end_vertex].append(start_vertex)
    in_degree[end_vertex] += 1



### 각 vertex의 edge들을 end_vertex의 incoming degree에 따라 내림차순 정렬함
for adj_vertice in adj_list:
    adj_vertice.sort(key=lambda x : -in_degree[x]) 



### 각 vertex를 incoming degree에 따라 내림차순 정렬함
vertice_list_sorted.sort(key=lambda x : -in_degree[x])



### 첫번째 dfs를 실행하는 함수
def dfs(current_vertex):
    visited[current_vertex] = True
    
    for adj_vertex in adj_list[current_vertex]:
        if not visited[adj_vertex]:
            dfs(adj_vertex)
    
    print(current_vertex, end=' ')
    stack.append(current_vertex)


### 두번째 transposed graph에 대한 dfs를 실행하는 함수
def dfs_t(current_vertex):
    visited[current_vertex] = True
    
    for adj_vertex in adj_list_t[current_vertex]:
        if not visited[adj_vertex]:
            dfs_t(adj_vertex)
    
    stack_t.append(current_vertex)



### Visited list안의 원소를 False로 초기화해주는 함수
def clear():
    for i in range(v+1):
        visited[i] = False
    
    
### Main 실행 영역
for vertex in vertice_list_sorted:
    if not visited[vertex]:
        dfs(vertex)
print()



clear()



while stack:
    vertex = stack.pop()
    if not visited[vertex]:
        dfs_t(vertex)
        
        while stack_t:
            member = stack_t.pop()
            scc[member] = vertex



for i in range(1, v+1):
    print(scc[i], end=' ')
print()