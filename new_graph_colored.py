
def printconfig(coloring_array):
    for i in range(4):
        print("color to vertex ", i, " is : ", coloring_array[i])


def issafe(graph, coloring_array):
    for i in range(4):
        for j in range(i+1, 4):
            if graph[i][j] and coloring_array[i] == coloring_array[j]:
                return False
    return True


def graphcolor(graph, m, coloring_array, vertex):
    if vertex == 4:
        if issafe(graph, coloring_array):
            printconfig(coloring_array)
            return True
        return False

    for i in range(m):
        coloring_array[vertex] = i
        if graphcolor(graph, m, coloring_array, vertex+1):
            return True
        coloring_array[vertex] =0
    return False




graph = [[0, 1, 1, 1],
         [1, 0, 1, 0],
         [1, 1, 0, 1],
         [1, 0, 1, 0]]

m = 3

coloring_array = [0 for i in range(4)]
vertex = 0

if graphcolor(graph, m, coloring_array, vertex):
    print("Solution Exists")
else:
    print("solution not exist")

