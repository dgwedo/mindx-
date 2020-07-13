board = [['-   ']*4,
         ['-   ']*4,
         ['-   ']*4,
         ['-   ']*4]
def print_board():
    for row in board:
        for column in row:
            print(column,end='')
        print()

print_board()

def check_win():
    #...
    pass


while True:
    inp = input('start(y/n):')
    if inp == 'y':
        row = int(input(">> row: "))
        column = int(input(">> column: "))
        board[row-1][column-1] ='x   '
        print_board()
    
    if inp =='n':
        break