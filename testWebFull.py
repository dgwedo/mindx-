from random import choice

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

def check(hit,enemy,rocket):

    if hit == False:
        print("You miss")
        print(enemy,"enemy(s) around")
        print(rocket,"rockets left")
        print(enemy,"enemy(s) left")
        
    if hit == True:
        print("You hit")
        print(enemy,"enemy(s) around")
        print(rocket,"rockets left")
        print(enemy,"enemy(s) left")
            
rocket = 5
enemy = 2
hit = False
while True:
    inp = input('start(y/n):')
    if inp == 'y':

        print('your target:')
        row = input(">> row(1-4): ")
        column = input(">> column(1-4): ")
        # board[int(row)-1][int(column)-1] ='x   '
        # print_board()

        ro = [x for x in range(1,5)]
        # ro.remove(int(row))
        col = [y for y in range(1,5)]
        # col.remove(int(column))
        choice_ro = choice(ro)
        choice_col = choice(col)


        if choice_ro == int(row) and choice_col == int(column):
            hit = True
            rocket = rocket -1
            enemy = enemy -1
            board[int(row)-1][int(column)-1] ='o   '
            print_board()
            check(hit,enemy,rocket)

            if enemy == 0 and rocket != 0:
                print('you win')
                break

            if rocket == 0 and enemy == 2:
                print("you lose")
                break

        if choice_ro != int(row) and choice_col != int(column):
            hit = False
            rocket = rocket -1
            board[int(row)-1][int(column)-1] ='x   '
            print_board()
            check(hit,enemy,rocket)
            
            if rocket == 0 and enemy == 2:
                print("you lose")
                break
                
        
        
    if inp =='n':
        break