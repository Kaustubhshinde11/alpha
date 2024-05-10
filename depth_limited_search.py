def dls(graph, start, depth_limit):

    stack = []
    visited = set()

    stack.append((start, 0))
    visited.add(start)

    while stack:

        vertex, limit = stack.pop()

        if limit <= depth_limit:
            print(vertex)


        for element in graph[vertex]:
            if element not in visited:
                stack.append((element, limit+1))
                visited.add(element)


graph = {
    '0': ['1', '2'],
    '1': ['0', '3', '4'],
    '2': ['0', '5'],
    '3': ['1'],
    '4': ['1'],
    '5': ['2']}

start = '0'
depth_limit = 2
dls(graph, start, depth_limit)


        
