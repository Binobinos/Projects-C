#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/*
Консольная Игра Морской Бой
*/

#define board_size_y 10
#define board_size_x 10
#define empty_char '.'
#define miss_char 'O'
#define player_ships '#'
#define broken_ship 'X'
#define break_ship '@'


void print_board(int rows, int cols, char board[rows][cols]){
    /*
    Выводит игровое поле на экран
    Аргументы:
    - rows - количество строк на поле
    - cols - количество столбцов на поле
    - board - игровое поле размером rows на cols

    */
    printf("   ");
    for (short x = 0; x < cols; x++){
        printf("  %c ", 65 + x);
    }
    printf("\n   |");
        for (short x = 0; x < cols * 2 - 1; x++){
            printf("--");
        }
    printf("-|\n");
    for (short y = 0; y < rows; y++){

        if (y < 9){printf(" %d |", y + 1);}
        else {printf("%d |", y + 1);}

        for (short x = 0; x < cols; x++){
            printf(" %c |", board[y][x]);
        }
        printf("\n   |");
        for (short x = 0; x < cols * 2 - 1; x++){
            printf("--");
        }
        printf("-|\n");
    }
}


void help_menu(){
    /*
    Выводит стартовое сообщение с правилами
    */
    printf("\tПривет. Это морской бой от Binobinos!\n");
    printf("\tВ этой игре твоя задача уничтожить все корабли соперника, пока он не уничтожил твои.\n");
    printf("Давай расскажу про правила:\n\n");
    printf("- Игровое поле имеет размер 10 на 10 клеток. (A3, C6, J3 и тд)\n");
    printf("- В твоем распоряжении флот из 10 кораблей. Ты расставляешь их на поле\n");
    printf("- Корабли не могут быть соприкасаться друг с другом\n");
    printf("- после расстановки кораблей бот также расставляет свои корабли.\n");
    printf("- Не ты, не он не ведите корабли друг друга.\n");
    printf("после начинается игра. Вы подбрасываете монетку кто первый ходит\n");
    printf("Далее ходит тот кому выпал орел.\n");
    printf("Игроки поочередно называют координату удара. Например A1\n");
    printf("- Если вы попали в корабль то он помечается как X\n");
    printf("- Если игрок промазал то клетка помечается символом O.\n");
    printf("- Если игрок сбил корабль то клетки корабля помечается символами @.\n");
    printf("Ваша задача расставить свой флот так, что вы успеете первым уничтожить флот противника чем он уничтожит ваш\n");
    printf("Веселитесь и найдите лучшую стратегию!\n");
    printf("Удачи!... \n\tby: Binobinos\n");
}


void main_menu(){
    /*
    Выводит текст главного меню
    */
    printf("\n\n\tГлавное меню. Выбери действие:\n\n");
    printf("- Начать Игру\n");
    printf("- Показать правила\n");
    printf("- Выход\n\n");
    printf("Выберете Действие: ");
}


void game_help_menu(int rows, int cols, char board[rows][cols]){
    /*
    Выводит краткую справку во время игры
    */
    printf("\n\nА перед началом познакомлю тебя с доской\n");
    printf("Перед тобой поле размером 10 на 10 клеток.\n");
    printf("По оси X указаны буквы, а по оси Y цифры. \n");
    printf("Чтобы обратится к определенной клетке сначала напиши букву, а потом цифру.\n");
    printf("Например C3 или I7.\n");
    print_board(rows, cols, board);
    printf("\n\n");
}


int randint(int min, int max){
    /*
    Возвращает случайное число в диапазоне [min, max]
    */
    return rand() % (max - min + 1) + min;
}


void ChoosingOrderGame(int* move){
    /*
    Игровая часть выбора хода и приветствия
    */
    int player_move = randint(0, 1), temp_exit = 1, is_orel;
    printf("Привет! Я Джо и твой соперник.\n");
    printf("Сегодня мы с тобой сразимся на поле битвы.");
    printf("Давай решим кто играет первым.\n");
    while (temp_exit){
        printf("Ты ставишь на орла или на решку?\nОрел - 1\nРешка - 0\n- Ваш выбор: ");
        scanf("%d", &is_orel);
        switch (is_orel){
            case 0: printf("Тогда я ставлю на Орла") ;temp_exit = 0; break;
            case 1: printf("Хм..я ставлю на Решку") ;temp_exit = 0; break;
            default: printf("Ей, чувак.. Давай ты выберешь Орла или решку!"); break;
        }
    }
    printf("\nВЫПАДАЕТ: ");
    if (player_move) {
        printf("ОРЕЛ\n");
    }
    else {
        printf("РЕШКА\n");
    }
    if (player_move == is_orel) {
        printf("Оу. Ты ходишь первым");
    }
    else {
        printf("Ха Ха. Сейчас хожу Я!");
    }
    *move = player_move == is_orel;
}


void Placement_ship_random(int ship[10][4][2]){
    int board[10][4][2];
    int num = 1;
    int coord_x, coord_y, fl, current_coord, temp_exit = 1, len_ship = 1, Direction, count_ship = 4, count_ship_copy = 4;
    int bot_board[board_size_y][board_size_x];
    for (short i = 0; i < board_size_y; i++){ // Инициализация доски
        for (short j = 0; j < board_size_x; j++){
            bot_board[i][j] = 1;
        }
    }
    for (int i = 0;i < 10;i++){
        temp_exit = 1;
        num = 0;
        while (temp_exit){
            coord_y = randint(0, board_size_y);
            coord_x = randint(0, board_size_x);
            Direction = randint(0, 1);
            current_coord = randint(0, 1);
            fl = 1;
            for (int j = 0;j < 4;j++){
                if (j < len_ship){
                    if (current_coord){
                        if (Direction){
                            coord_y -= 1;
                        }
                        else{
                            coord_y += 1;
                        }
                    }
                    else{
                        if (Direction){
                            coord_x -= 1;
                        }
                        else{
                            coord_x += 1;
                        }
                    }
                    if (bot_board[coord_y][coord_x] == 0 || coord_y > 10 || coord_y < 1 || coord_x > 10 || coord_x < 1){
                        fl = 0;
                    }
                }
            }
            if (fl == 1){
                temp_exit = 0;
            }
            else{
                // printf("Корабль не удачный. попытка %d", num + 1);
            }
            num += 1;
            if (num >= 100){
            }
        }
        // printf("Корабль длинной %d начальной координатой %c%d и направлением %d по оси %d(1 - Y, 0 - X)\n", len_ship, coord_y + 65, coord_x, Direction, current_coord);
        for (int j = 0;j < 4; j++){
                if (j < len_ship){
                    board[i][j][0] = coord_y;
                    board[i][j][1] = coord_x;
                    if (current_coord){
                        if (Direction){
                            coord_y -= 1;
                        }
                        else{
                            coord_y += 1;
                        }
                    }
                    else{
                        if (Direction){
                            coord_x -= 1;
                        }
                        else{
                            coord_x += 1;
                        }
                    }
                    if (bot_board[coord_y][coord_x] == 0 || coord_y > 10 || coord_y < 0 || coord_x > 10 || coord_x < 0){
                        fl = 0;
                    }
                }
                else {
                    board[i][j][0] = -1;
                    board[i][j][1] = -1;
                }
            // printf("\tКоординаты %c%d Длинна %d\\%d \n", coord_y + 65, coord_x, j + 1, len_ship);
        }
        count_ship -= 1;
        if (count_ship <= 0){
            count_ship_copy -= 1;
            count_ship = count_ship_copy;
            len_ship += 1;
            }

    }
    for (short i = 0; i < 10; i++){ // Инициализация доски
        for (short j = 0; j < 4; j++){
            ship[i][j][0] = board[i][j][0];
            ship[i][j][1] = board[i][j][1];
        }
    }
}


void Placement(int ships_bot[10][4][2], int ships_player[10][4][2]){
    int temp_exit = 1, player_setting_move;
    while (temp_exit){
         printf("Выбери режим расстановки:\nРучной - 1\nАвтоматически - 0\n- Ваш выбор: ");
        scanf("%d", &player_setting_move);
        switch (player_setting_move){
            case 0: printf("О, ДА!.Binobinos, блин. Как тебе делать Выбор без Выбора? А?") ;temp_exit = 0; Placement_ship_random(ships_player);; break; // TODO: Сделать Ручной режим расстановки
            case 1: printf("Временно не работает, я как настоящий Джо бы тоже выбрал бы этот режим, но binobinos почему-то не сделал его..") ; break; // TODO: Сделать Ручной режим расстановки
            default: printf("Ей, чувак.. Давай ты выберешь режим а не фигню!"); break;
        }
    }
    printf("\nОкей. Расстановка законченна. Теперь я расставляю!\n");
    // TODO: Сделать автоматическую расстановку бота
    Placement_ship_random(ships_bot);
    printf("Окей.. Я так расставил как ты никогда не узнаешь.\n");
}


void main_play(){
    /*
    Основной цикл игры.
    */
    // Инициализация переменных
    int is_orel, temp_exit = 1, player_setting_move, game_loop = 1, bot_x, bot_y, move_y, move_player;
    int bot_move_map[board_size_y][board_size_x], ships_player[10][4][2], ships_bot[10][4][2];
    char player_board[board_size_y][board_size_x], bot_board[board_size_y][board_size_x], move_char, move_x;

    for (short i = 0; i < board_size_y; i++){ // Инициализация доски
        for (short j = 0; j < board_size_x; j++){
            player_board[i][j] = empty_char;
            bot_board[i][j] = empty_char;
            bot_move_map[i][j] = 1;
        }
    }

    ChoosingOrderGame(&is_orel); // Выбор порядка игры
    game_help_menu(10, 10, player_board); // Справка
    Placement(ships_bot, ships_player); // Расстановка
    // Основной цикл Игры
    printf("Ну ладно. Хватит пустых слов. Давай сыграем!\n");
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 4; j++){
            if (ships_player[i][j][0] != -1 && ships_player[i][j][0] != -1){
                player_board[ships_player[i][j][0]][ships_player[i][j][1]] = player_ships;
            }
        }
    }

    while (game_loop){
        move_player = 1;
        printf("\n\nПОЛЕ ДЖО\n");
        print_board(board_size_y, board_size_x, bot_board);
        printf("\n\nВАШЕ ПОЛЕ\n");
        print_board(board_size_y, board_size_x, player_board);

        while (move_player){
            printf("Куда стреляем капитан?(Буква+цифра): ");
            scanf(" %c%d", &move_x, &move_y);
            move_x = toupper(move_x);
            printf("Вы ввели %c%d \n", move_x, move_y);
            if ('A' > move_x || move_x > 'J' || 1 > move_y || move_y > 10) {
                printf("НЕ Координаты корректные. пожалуйста введите снова");
                game_loop = 0;
                break;
            }
            else {
                move_player = 0;
            }
        }
        if (game_loop == 0){
            break;
        }
        move_char = miss_char;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 4; j++){
                if (ships_bot[i][j][0] == move_y - 1 && ships_bot[i][j][1] == move_x - 'A'){
                    move_char = broken_ship;
                }
            }
        }
        bot_board[move_y - 1][move_x - 'A'] = move_char;

        bot_x = randint(0, 9);
        bot_y = randint(0, 9);
        printf("Мой Ход %c%d",(bot_x + 'A'), (bot_y + 1));
        move_char = miss_char;
        for (int i = 0; i < 10; i++){
            for (int j = 0; i < 4; i++){
                if (ships_player[i][j][0] == bot_y && ships_player[i][j][1] == bot_x){
                    move_char = broken_ship;
                }
            }
        }
        player_board[bot_y][bot_x] = move_char;
    }
        // TODO: Написать бесконечную проверку пока не будут верные координаты. Ход игрока пока он попадает. Ходы Бота и проверку на выигрыш
}



int main(void){
    /*
    Основная Функция Игры
    */
    srand(time(NULL));
    short exit = 1;
    unsigned short action;
    help_menu();
    while (exit){
        main_menu();
        scanf("%d", &action);
        printf("\n");
        switch (action){
            case 1: main_play(); break;
            case 2: help_menu(); break;
            case 3: printf("Пока, может еще увидимся!"); exit = 0; break;
            default: printf("Неверная команда. попробуйте еще раз\n"); break;
        }
    }
    return 0;
}