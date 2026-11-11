#include <stdio.h>

#define SIZE 5

char board[SIZE][SIZE];

// Initialize board
void initboard(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = ' ';
        }
    }
}

// Print board
void printboard(){
    printf("\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%c", board[i][j]);
            if(j < SIZE - 1) printf(" | ");
        }
        printf("\n");

        if(i < SIZE - 1){
            for(int k = 0; k < SIZE; k++){
                printf("---");
                if(k < SIZE - 1) printf("+");
            }
            printf("\n");
        }
    }
}

// Make move
void makemove(char player){
    int row, column;

    while(1){
        printf("Player %c: enter row and column (0-4): ", player);
        scanf("%d %d", &row, &column);

        if(row < 0 || row >= SIZE || column < 0 || column >= SIZE){
            printf("Invalid position! Try again.\n");
            continue;
        }

        if(board[row][column] != ' '){
            printf("Spot already taken! Try again.\n");
            continue;
        }

        board[row][column] = player;
        break;
    }
}

// Check winner (5 in a row)
char checkWinner(){

    // Rows
    for(int i = 0; i < SIZE; i++){
        int win = 1;
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] != board[i][0] || board[i][0] == ' '){
                win = 0;
                break;
            }
        }
        if(win) return board[i][0];
    }

    // Columns
    for(int j = 0; j < SIZE; j++){
        int win = 1;
        for(int i = 0; i < SIZE; i++){
            if(board[i][j] != board[0][j] || board[0][j] == ' '){
                win = 0;
                break;
            }
        }
        if(win) return board[0][j];
    }

    // Main diagonal
    int win = 1;
    for(int i = 0; i < SIZE; i++){
        if(board[i][i] != board[0][0] || board[0][0] == ' '){
            win = 0;
            break;
        }
    }
    if(win) return board[0][0];

    // Secondary diagonal
    win = 1;
    for(int i = 0; i < SIZE; i++){
        if(board[i][SIZE - i - 1] != board[0][SIZE - 1] || board[0][SIZE - 1] == ' '){
            win = 0;
            break;
        }
    }
    if(win) return board[0][SIZE - 1];

    return ' ';
}

int main(){
    char player = 'X';
    char winner;

    initboard();

    for(int i = 0; i < SIZE * SIZE; i++){
        printboard();
        makemove(player);

        winner = checkWinner();
        if(winner != ' '){
            printboard();
            printf("\nPlayer %c wins!\n", winner);
            return 0;
        }

        // Switch player
        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    printboard();
    printf("\nIt's a draw!\n");

    return 0;
}