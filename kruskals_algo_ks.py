def find_parent(parent, vertex):
    if parent[vertex] != vertex:
        parent[vertex] = find_parent(parent, parent[vertex])
    return parent[vertex]

def union(parent, rank, v1, v2):
    r1 = find_parent(parent, v1)
    r2 = find_parent(parent, v2)

    if r1 != r2:
        if rank[r1] > rank[r2]:
            parent[r2] = r1

        elif rank[r2] > rank[r1]:
            parent[r1] = r2

        else:
            parent[r2] = r1
            rank[r1] += 1

def kruskal(graph):
    mst = []
    edges = []

    for i in range(len(graph)):
        for j in range(i+1, len(graph)):
            if graph[i][j] != 0:
                edges.append((graph[i][j], i, j))
        
    edges.sort()

    parent = {vertex: vertex for vertex in range(len(graph))}
    rank = {vertex: 0 for vertex in range(len(graph))}

    for weight, u, v in edges:
        if find_parent(parent, u) != find_parent(parent, v):
            mst.append((weight, u, v))
            union(parent, rank, u, v)

    return mst

graph = [[0, 9, 75, 0, 0],
     [9, 0, 95, 19, 42],
     [75, 95, 0, 51, 66],
     [0, 19, 51, 0, 31],
     [0, 42, 66, 31, 0]]



ans = kruskal(graph)
print(ans)


