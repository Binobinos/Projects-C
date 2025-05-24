#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
/*
Консольная Игра Морской Бой
*/

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
        printf("%c ", 65 + x);
    }
    printf("\n   ");
        for (short x = 0; x < cols * 2; x++){
            printf("-");
        }
    printf("\n");
    for (short y = 0; y < rows; y++){

        if (y < 9){printf("%d |", y + 1);}
        else {printf("%d|", y + 1);}

        for (short x = 0; x < cols; x++){
            printf("%c|", board[y][x]);
        }
        printf("\n   ");
        for (short x = 0; x < cols * 2; x++){
            printf("-");
        }
        printf("\n");
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
    printf("- Если вы попали в корабль то он помечается как @\n");
    printf("- Если игрок промазал то клетка помечается символом O.\n");
    printf("- Если игрок сбил корабль то клетки корабля помечается символами #.\n");
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


void game_help_menu(){
    /*
    Выводит краткую справку во время игры
    */
    printf("\n\nА перед началом познакомлю тебя с доской\n");
    printf("Перед тобой поле размером 10 на 10 клеток.\n");
    printf("По оси X указаны буквы, а по оси Y цифры. \n");
    printf("Чтобы обратится к определенной клетке сначала напиши букву, а потом цифру.\n");
    printf("Например C3 или I7.\n");
    print_board(board_size_y, board_size_x, player_board);
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

void Placement(){
    int temp_exit = 1;
    while (temp_exit){
         printf("Выбери режим расстановки:\nРучной - 1\nАвтоматически - 0\n- Ваш выбор: ");
        scanf("%d", &player_setting_move);
        switch (player_setting_move){
            case 0: printf("О, ДА!.Binobinos, блин. Как тебе делать Выбор без Выбора? А?") ;temp_exit = 0; break; // TODO: Сделать Ручной режим расстановки
            case 1: printf("Временно не работает, я как настоящий Джо бы тоже выбрал бы этот режим, но binobinos почему-то не сделал его..") ; break; // TODO: Сделать Ручной режим расстановки
            default: printf("Ей, чувак.. Давай ты выберешь режим а не фигню!"); break;
        }
    printf("\nОкей. Расстановка законченна. Теперь я расставляю!\n");
    // TODO: Сделать автоматическую расстановку бота
    printf("Окей.. Я так расставил как ты никогда не узнаешь.\n");
}


void main_play(){
    /*
    Основной цикл игры.
    */
    // Инициализация переменных
    const int board_size_y = 10, board_size_x = 10;
    const char empty_char = '.', player_ship = 'O', broken_ship = 'X', break_ship = '@';
    int is_orel, temp_exit = 1, player_setting_move, game_loop = 1, bot_x, bot_y, move_y, move_player;
    int ship[10][4][2] = {{{0, 0}, {0, 1}, {0, 2}, {0, 3}}};
    int bot_move_map[board_size_y][board_size_x];
    char player_board[board_size_y][board_size_x], bot_board[board_size_y][board_size_x];
    char move_char, move_x;
    move_char = break_ship;

    for (short i = 0; i < board_size_y; i++){ // Инициализация доски
        for (short j = 0; j < board_size_x; j++){
            player_board[i][j] = empty_char;
            bot_board[i][j] = empty_char;
            bot_move_map[i][j] = 1;
        }
    }

    ChoosingOrderGame(&is_orel); // Выбор порядка игры
    game_help_menu(); // Справка
    Placement() // Расстановка
    // Основной цикл Игры
    printf("Ну ладно. Хватит пустых слов. Давай сыграем!\n");
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
            }
            else {
                move_player = 0;
            }
        move_char = player_ship;
        for (int i = 0; i < 4; i++){
            if (ship[i][0] == move_y - 1 && ship[i][1] == move_x - 'A'){
                move_char = broken_ship;
            }
        }
        bot_board[move_y - 1][move_x - 'A'] = move_char;
        bot_x = randint(0, 9);
        bot_y = randint(0, 9);
        printf("Мой Ход %c%d",(bot_x + 'A'), (bot_y + 1));
        move_char = player_ship;
        for (int i = 0; i < 4; i++){
            if (ship[i][0] == bot_y && ship[i][1] == bot_x){
                move_char = broken_ship;
            }
        }
        player_board[bot_y][bot_x] = move_char;
        bot_move_map[bot_y][bot_x] = 0;

        }
        // TODO: Написать бесконечную проверку пока не будут верные координаты. Ход игрока пока он попадает. Ходы Бота и проверку на выигрыш
        // game_loop = 0;
    }
    }
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