for i in range(4):
    for j in range(4):
        print("_  ",end='')
    print()

while True:
    inp = input("yes/no:(y/n)")
    if inp == 'y':
        row = int(input(">> row: "))
        column = int(input(">> column: "))
        for target1 in range(4):
            for target2 in range(4):
                if target2 == row:
                    print('x ',end='')
                else:
                    print("_  ",end='')
            if target1 == column:
                print('x')
            else:
                print()
    if inp =='n':
        break
