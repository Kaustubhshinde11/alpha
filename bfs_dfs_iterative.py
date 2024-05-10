import collections

def dfs(graph, start):

    stack = []
    visited = set()

    stack.append(start)
    visited.add(start)

    while stack:

        vertex = stack.pop()

        print(vertex)

        for element in graph[vertex]:
            if element not in visited:
                stack.append(element)
                visited.add(element)



def bfs(root, graph):
    new, queue = set(), collections.deque([root])

    new.add(root)

    while queue:

        vertex = queue.popleft()
        print(vertex)

        for element in graph[vertex]:
            if element not in new:
                queue.append(element)
                new.add(element)

graph = {
    '0': ['1', '2'],
    '1': ['0', '3', '4'],
    '2': ['0', '5'],
    '3': ['1'],
    '4': ['1'],
    '5': ['2']}

root = "0"
start = "0"

bfs(root, graph)
print()
dfs(graph, start)
                
