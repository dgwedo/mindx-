#include <stdio.h>


char board[3][3]; 
int winner; 
bool endGame; 

// khởi tạo bàn cờ và một số dữ liệu khác trong game
void initBoard()
{
    endGame = false; 
    for (int i=0; i<=2; i++)
    {
        for (int j=0; j<=2; j++)
        {
            board[i][j] = '*';
        }
    }
}

// hàm này kiểm tra xem bàn cờ còn ô nào trống khôn
// nếu còn thì trả về false, không thì true
bool blank()
{
    for (int i=0; i<=2; i++)
    {
        for (int j=0; j<=2; j++)
        {
            if (board[i][j] == '*') return true;
        }
    }
    return false;
}


void checkWin(){
  int i;
  char key = '*';
  winner = 0;
  endGame = false;

     for (i=0; i<3;i++)
        if (board [i][0] == board [i] [1] && board [i][0] == board [i] [2] && board [i] [0] != '*') key = board [i] [0];
      
     for (i=0; i<3;i++)
        if (board [0][i] == board [1] [i] && board [0][i] == board [2] [i] && board [0] [i] != '*') key = board [0] [i];
            
     if (board [0][0] == board [1] [1] && board [1][1] == board [2] [2] && board [1] [1] != '*') key = board [1] [1];
     if (board [0][2] == board [1] [1] && board [1][1] == board [2] [0] && board [1] [1] != '*') key = board [1] [1];
          
    if (key == 'X')
    {
      winner = 1; 
      endGame = true; 
    }
    if (key == 'O')
    {
      winner = 2; 
      endGame = true; // cũng end game luôn
    }

    // còn nếu mà hết ô trống rồi thì cũng end game, nếu winner vẫn bằng 0 thì là hòa
    if (blank() == false)
    {                        
        endGame = true;
    }
}

// in ra cái bàn cờ
void drawBoard()
{
    
    for (int i=0; i<=2; ++i)
    {
        for (int j=0; j<=2; ++j)
        {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
    }
}

// đây chính là phần quan trọng nhất, vòng lặp chính
void playGame()
{
    int x,y; // ta tạo 2 biến x và y để nhập nước đi

    // lặp chừng nào endGame vẫn còn false
    while (endGame == false)
    {
        // phải thêm cái này vì trước mỗi nước đi ta sẽ kiểm tra xem đã kết thúc game chưa
        // nếu chưa thì cho người chơi nhập tiếp, còn end rồi thì thôi, dừng.
        if (endGame == false)
        {
            // ta làm một cái mốc et để nhập nước đi cho player 1
        et:    printf("Player 1 nhap nuoc di: ");
            std::cin >> x;
            std::cin >> y;

            if ( (x<=3) || (y<=3) ) // nếu mà giá trị nhập vào hợp lệ thì xử lý tiếp
            {
                if (board[x-1][y-1] == '*'){ // nếu ô người chơi nhập vào còn trống
                    board[x-1][y-1] = 'X'; // thì đánh vào quân X
                    checkWin(); // đồng thời kiểm tra xem đã thắng chưa
                }else{
                    // nếu ô người chơi nhập vào không còn trống (tức là đã có X hoặc O)
                    // thì nhảy về mốc er1 để báo lỗi và cho người chơi nhập lại
                    goto er1;
                }
                printf("--> Player 1: %d - %d\n", x, y); // ghi lại các nước đi cho dễ theo dõi
            }else
            {
                // mốc er1 để báo lỗi game với người chơi 1
                er1: printf("Nhap sai!\n");
                goto et; // báo lỗi xong thì nhảy về et để nhập nước đi lại
            }
            
            drawBoard(); // đi xong thì in bàn cờ ra
        }

        // tương tự, trước khi player 2 ra nước đi, ta cũng kiểm tra xem game đã kết thúc chưa
        if (endGame == false)
        {
            // mốc et2 là để player 2 nhập nước đi
            // dưới đây cũng giống như đối với player 1 nên không cần comment nữa
        et2: printf("Player 2 nhap nuoc di: ");
             std::cin >> x;
            std::cin >> y;
            if ( (x<=3) || (y<=3) )
            {
                if (board[x-1][y-1] == '*'){
                    board[x-1][y-1] = 'O';
                    checkWin();
                }else{
                    goto er2;
                }
                printf("--> Player 2: %d - %d\n", x, y);
            }else
            {
                er2: printf("Nhap sai!\n");
                goto et2;
            }
            
            drawBoard();
        }
    }
    // Nếu endGame = true thì kết thúc trò chơi, in ra kết quả
    printf("Ket thuc!\n");
    switch(winner) // kiểm tra winner
    {
    case 0: // nếu bằng 0 là hòa
        printf("Hoa!\n"); break;
    case 1: // nếu bằng 1 là player 1 thắng
        printf("Player 1 thang!\n"); break;
    case 2: // bằng 2 là player 2 thắng
        printf("Player 2 thang!\n"); break;
    }
    getchar();
}

int main(int argc, char* argv[])
{
    initBoard();
    drawBoard();
    playGame();
    getchar();
    return 0;
}