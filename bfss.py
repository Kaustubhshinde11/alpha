import heapq

def bfss(graph, start):

    distances = {node: float('infinity') for node in graph}
    
    distances[start] = 0
    priority_queue = [(start, distances[start])]

    while priority_queue:

        curr_node, curr_dist = heapq.heappop(priority_queue)

        if curr_dist > distances[curr_node]:
            continue


        for neighbor, weight in graph[curr_node]:

            distance = weight + curr_dist

            if distance < distances[neighbor]:
                distances[neighbor] =  distance
                heapq.heappush(priority_queue, (neighbor, distance))



    return distances

graph = {
    'A': [('B', 5), ('C', 10)],
    'B': [('A', 5), ('C', 8), ('D', 4)],
    'C': [('A', 10), ('B', 8), ('D', 6)],
    'D': [('B', 4), ('C', 6)]}

start = "A"

ans = bfss(graph, start)

print("Start node: ", start)
for node, val in ans.items():
    print("To node ", node + " : ", val)

