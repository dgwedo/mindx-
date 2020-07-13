for i in range(4):
    for j in range(4):
        print("_  ",end='')
    print()
def printBoardCurrent(column,row):
    for target1 in range(4):
            for target2 in range(4):
                if target2 == column and target1 == row-1:
                    print('x  ',end='')
                else:
                    print('_  ',end='')
            print()

while True:
    inp = input("yes/no:(y/n)")
    if inp == 'y':
        row = int(input(">> row: "))
        column = int(input(">> column: "))
        printBoardCurrent(column,row)
    if inp =='n':
        break
