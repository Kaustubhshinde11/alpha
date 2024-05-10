import heapq


def astar(start, goal, graph, heuristic):
    # creating the two lists
    open_set = []
    closed_set = set()

    # making the dictionaries for the f(n),g(n) and for the parent
    g = {start: 0}
    f = {start: g[start] + heuristic[start]}
    parent = {start: None}

    # push the start node in the open_set
    heapq.heappush(open_set, (f[start], start))

    while open_set:
        # pop the element from the heap
        current_node = heapq.heappop(open_set)[1]
        # print(current_node)

        # checking the current node is the goal node or not
        if current_node == goal:
            # creating the list for storing the answer path
            path = []
            while current_node:
                path.append(current_node)
                current_node = parent[current_node]
            return path[::-1]

        # if the current node is not goal node the mark the node as visited by inserting on the closed_set
        closed_set.add(current_node)

        # now iteratively performing the operation on the neighbour node for the current node
        for neighbour in graph[current_node]:
            if neighbour in closed_set:
                continue
            # calculate the g value
            # assuming the distance from the parent node is 1
            neighbour_g = g[current_node] + 1
            if neighbour not in g or neighbour_g < g[neighbour]:
                # updating the g(n),h(n),parent and push the node in a openset
                g[neighbour] = neighbour_g
                f[neighbour] = g[neighbour] + heuristic[neighbour]
                parent[neighbour] = current_node
                heapq.heappush(open_set, (f[neighbour], neighbour))

    return []


graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B', 'G'],
    'E': ['B', 'H'],
    'F': ['C', 'I'],
    'G': ['D', 'H'],
    'H': ['G', 'E', 'I'],
    'I': ['F', 'H']
}

heuristic = {
    'A': 5,
    'B': 4,
    'C': 3,
    'D': 2,
    'E': 3,
    'F': 2,
    'G': 1,
    'H': 2,
    'I': 0
}
start = 'A'
goal = 'I'
path = astar(start, goal, graph, heuristic)
if path:
    print("Path Found")
    print("->".join(path))
else:
    print("Path not found")
