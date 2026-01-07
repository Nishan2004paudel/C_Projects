#include <stdio.h>

void printBoard(char board[3][3]){
    printf("\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf(" %c", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin (char board[3][3], char mark){
    for (int i = 0; i< 3; i++){
        if (board[i][0]==mark && board[i][1]== mark && board[i][2]==mark) return 1;
        if (board[0][i]==mark && board[1][i]== mark && board[2][i]==mark) return 1;
    }
    if (board[0][0]==mark && board[1][1]== mark && board[2][2]==mark) return 1;
    if (board[0][2]==mark && board[1][1]== mark && board[2][0]==mark) return 1;
    return 0;
}




int main() {
    char board[3][3]={
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    int player = 1;
    int choice; 
    char mark;
    int moves =0 ;

    printf("Tic Tac Toe Game for 2 players \n");

    while (1){
        printBoard(board);
        mark= (player ==1)? 'X' : 'O';

        printf("Player %d, enter your choice (1-9):", player);
        scanf("%d", &choice);

    

        int row = (choice -1)/3;
        int col = (choice -1 )%3;

        if (board[row][col]=='X' || board[row][col]=='O'){
            printf("Cell already taken! Choose another.\n");
            continue;
        }

        board[row][col]= mark;
        moves ++;

        if (checkWin(board, mark)){
            printBoard(board);
            printf("Player %d wins! \n", player);
            break;
        }
        if (moves ==9){
            printBoard(board);
            printf("It's a draw !\n");
            break;
        }
        player = (player == 1)? 2: 1;
    }
    return 0;
}