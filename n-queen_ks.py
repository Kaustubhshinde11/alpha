def is_safe(board, row, col ,n):

    for i in range(row):
        if board[i][col] == 1:
            return False

    i = row-1
    j = col-1
    while i>=0 and j>=0:
        if board[i][j] == 1:
            return False

        i -= 1
        j -= 1

    i = row-1
    j = col+1
    while i>=0 and j<n:
        if board[i][j] == 1:
            return False

        i -= 1
        j += 1

    return True

def is_valid(board, row, col, n):

    for i in range(row+1, n):
        if board[i][col] == 1:
            return False

    i = row-1
    j = col-1
    while i>=0 and j>=0:
        if board[i][j] == 1:
            return False

        i -= 1
        j -= 1

    i = row-1
    j = col+1
    while i>=0 and j<n:
        if board[i][j] == 1:
            return False

        i -= 1
        j += 1

    return True

def solve(board, row, n):
    if row == n:
        print_solution(board, n)
        print()
        

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 1
            if is_valid(board, row, col, n):

                solve(board, row+1, n)
                board[row][col] = 0

def print_solution(board, n):
    for i in range(n):
        for j in range(n):
            print(board[i][j], end = " ")
        print()

n = 4
row = 0
board = [[0]*n for _ in range(n)]
solve(board, row, n)
#print("Total solutions are", count)

        
