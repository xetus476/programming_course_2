def konec(n):
    def is_safe(board, i_ferz, j_ferz):
        if board[i_ferz][j_ferz]!= 0 :
            return False

        return True

    def zap(board, i_ferz, j_ferz, n):
        board[i_ferz][j_ferz] = 2
        for i in range(n):
            for j in range(n):
                if board[i][j] != 2:  
                    if (i == i_ferz) or (j == j_ferz) or (abs(i - i_ferz) == abs(j - j_ferz)):
                        board[i][j] = 1
        return board

    def podscet(board, row, n):
        if row == n:
            #schet +=1
            #solution.append(board.copy)
            return 1
        
        total = 0
        for col in range(n):
            if is_safe(board, row, col):
                board_copy = [row[:] for row in board]
                board = zap(board, row, col, n)
                #schet += 1
                total += podscet(board, row + 1, n)
                board = board_copy

        return total

    solution = []
    board = [[0 for i in range(n)] for _ in range (n)]
    schet = podscet(board, 0, n)
    return schet

    
n = 9
solution = []
board = [[0 for i in range(n)] for _ in range (n)]
print(konec(n))

