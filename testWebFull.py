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
# RiLe = ['left','right']
# case = choice(RiLe)
def check(hit,enemy,rocket):

        if hit == False:
            print("You miss")
            print(enemy,"enemy(s) around")
            rocket = rocket - 1
            print(rocket,"rockets left")
            print(enemy,"enemy(s) left")
            
        if hit == True:
            print("You hit")
            enemy = enemy-1
            print(enemy,"enemy(s) around")
            rocket = rocket - 1
            print(rocket,"rockets left")
            print(enemy,"enemy(s) left")
            

while True:
    inp = input('start(y/n):')
    if inp == 'y':
        rocket = 5
        enemy = 2
        hit = False

        print('your target:')
        row = input(">> row: ")
        column = input(">> column: ")
        # board[int(row)-1][int(column)-1] ='x   '
        # print_board()

        ro = [x for x in range(5)]
        # ro.remove(int(row))
        col = [y for y in range(5)]
        # col.remove(int(column))
        choice_ro = choice(ro)
        choice_col = choice(col)


        if int(row) == choice_ro and int(column)== choice_col:
            hit = True
            board[int(row)-1][int(column)-1] ='o   '
            print_board()
            check(hit,enemy,rocket)
            if enemy == 0 :
                print('you win')
                break

            if rocket == 0 and enemy == 2:
                print("you lose")
                break

        if int(row) != choice_ro and int(column) != choice_col:
            hit = False
            board[int(row)-1][int(column)-1] ='x   '
            print_board()
            check(hit,enemy,rocket)
            if rocket == 0 and enemy == 2:
                print("you lose")
                break
                
        
        
    if inp =='n':
        break