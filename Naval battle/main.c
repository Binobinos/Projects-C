#include <stdio.h>
/*
Консольная Игра Морской Бой
*/

void print_board(int rows, int cols, char board[rows][cols]){
    /*
    Выводит игровое поле на экран
    */
    printf("   ");
    for (int x = 0; x < cols; x++){
        printf("%c ", 65 + x);
    }
    printf("\n   ");
        for (int x = 0; x < cols * 2; x++){
            printf("-");
        }
    printf("\n");
    for (int y = 0; y < rows; y++){

        if (y < 9){printf("%d |", y + 1);}
        else {printf("%d|", y + 1);}

        for (int x = 0; x < cols; x++){
            printf("%c|", board[y][x]);
        }
        printf("\n   ");
        for (int x = 0; x < cols * 2; x++){
            printf("-");
        }
        printf("\n");
    }
}

int main(void){
    /*
    Основная Функция программы
    */
    const char empty_char = '.', player_ship = 'O', broken_ship = '@', break_ship = 'X';
    int board_size_y = 10, board_size_x = 10;
    char board[board_size_y][board_size_x];

    for (int i = 0; i < board_size_y; i++){
        for (int j = 0; j < board_size_x; j++){
            board[i][j] = empty_char;
        }
    }
    print_board(board_size_y, board_size_x, board);
    return 0;
}