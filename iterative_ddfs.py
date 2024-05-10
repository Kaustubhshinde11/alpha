def iddfs(graph,start,goal):
    depth_limit = 0
    while True:

        ans = dfs(graph, start, goal, depth_limit)
        if ans == "found":
            print("Found at ", depth_limit)
            break
        depth_limit += 1
    

def dfs(graph, start, goal, depth_limit):

    stack = []
    visited = set()

    stack.append((start, 0))
    visited.add(start)

    while stack:

        vertex, dl = stack.pop()

        if dl <= depth_limit:

            if vertex == goal:
                return "found"
                break

            for elem in graph[vertex]:
                if elem not in visited:
                    stack.append((elem, dl+1))
                    visited.add(elem)

    return "not found"

graph = {
    '0': ['1', '2'],
    '1': ['0', '3', '4'],
    '2': ['0', '5'],
    '3': ['1'],
    '4': ['1'],
    '5': ['2']}

start = '0'
goal = '1'
iddfs(graph,start,goal)
