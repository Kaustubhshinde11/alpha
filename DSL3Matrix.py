m = int(input("Enter the number of rows: "))
n = int(input("Enter the number of columns: "))



def matrix(m, n):
    o = []
    for i in range(m):
        row = []
        for j in range(n):
            element = int(input("Enter the A[i][j] element: "))
            row.append(element)
        o.append(row)

    return o

def sum(A, B):
    s = []
    for i in range(m):
        row = []
        for j in range(n):
            add = A[i][j] + B[i][j]
            row.append(add)
        s.append(row)

    return s

def difference(A, B):
    d = []
    for i in range(m):
        row = []
        for j in range(n):
            subtract = A[i][j] - B[i][j]
            row.append(subtract)
        d.append(row)
    return d


    


A = matrix(m, n)
print(A)

B = matrix(m, n)
print(B)

C = sum(A, B)
print(C)

D = difference(A, B)
print(D)

E = [[0, 0, 0],
     [0, 0, 0],
     [0, 0, 0]]

def multiplication():
    for i in range(0, len(E)):
        for j in range(0, len(E[0])):
            for k in range(0, len(B)):
                E[i][j] += A[i][k]*B[k][j]

multiplication()
print(E)

def transpose():
    for i in range(len(A)):
        for j in range(len(A[0])):
            E[j][i] = A[i][j]

transpose()
print(E)

