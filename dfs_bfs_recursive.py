import collections

def dfs_rec(visited, stack, graph):

    if not stack:
        return

    vertex = stack.pop()
    print(vertex)

    for elem in graph[vertex]:
        if elem not in visited:
            stack.append(elem)
            visited.add(elem)

    dfs_rec(visited, stack, graph)
    

def dfs(start, graph):

    stack = []
    visited = set()

    stack.append(start)
    visited.add(start)

    dfs_rec(visited, stack, graph)


def bfs_rec(visited, queue, graph):

    if not queue:
        return

    vertex = queue.popleft()
    print(vertex)

    for elem in graph[vertex]:
        if elem not in visited:
            queue.append(elem)
            visited.add(elem)

    bfs_rec(visited, queue, graph)


def bfs(start, graph):

    
    queue = collections.deque([start])

    visited = set()

    visited.add(start)

    bfs_rec(visited, queue, graph)



graph = {
    '0': ['1', '2'],
    '1': ['0', '3', '4'],
    '2': ['0', '5'],
    '3': ['1'],
    '4': ['1'],
    '5': ['2']}

start = "0"
dfs(start, graph)
print()
bfs(start, graph)

    
