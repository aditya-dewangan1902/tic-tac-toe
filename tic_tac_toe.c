#include <stdio.h>

#define ROWS 3
#define COLS 3

void init_board(char board[ROWS][COLS]) {
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            board[i][j] = ' ';
        }
    }
}

void draw_board(char board[ROWS][COLS]) {
    printf("\n");
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf(" %c ", board[i][j]);
            if(j<2) printf("|");
        }
        printf("\n");
        if(i<2) printf("---|---|---\n");
    }
    printf("\n");
}

int check_win(char board[ROWS][COLS]) {
    for(int i=0;i<ROWS;i++){
        if(board[i][0] != ' ' &&
           board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
           return 1;
    }
    for(int i=0;i<COLS;i++){
        if(board[0][i] != ' ' &&
           board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
           return 1;
    }
    if(board[0][0] != ' ' &&
       board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
       return 1;

    if(board[0][2] != ' ' &&
       board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
       return 1;

    return 0;
}

int check_draw(char board[ROWS][COLS]) {
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int main() {
    char board[ROWS][COLS];
    char current = 'X';
    int pos;
    int gameOver = 0;

    init_board(board);

    while(!gameOver) {
        draw_board(board);
        printf("Player %c enter position (1-9): ", current);
        scanf("%d", &pos);

        if(pos < 1 || pos > 9) {
            printf("Invalid!\n");
            continue;
        }

        int r = (pos-1)/3;
        int c = (pos-1)%3;

        if(board[r][c] != ' ') {
            printf("Already filled!\n");
            continue;
        }

        board[r][c] = current;

        if(check_win(board)) {
            draw_board(board);
            printf("Player %c Wins!\n", current);
            gameOver = 1;
        }
        else if(check_draw(board)) {
            draw_board(board);
            printf("Draw!\n");
            gameOver = 1;
        }
        else {
            if(current == 'X') current = 'O';
            else current = 'X';
        }
    }

    return 0;
}
