#include <stdio.h>

typedef float fl;


int main(void){
    int exit = 0;
    fl value_a, value_b;
    char operator_calc;
    printf("Привет! Это мини-калькулятор на C от binobinos\n");
    while (exit != 1){
        printf("Введите любое число или \"1\": ");
        scanf("%d", &exit);
        if (exit == 1){break;}
        printf("Введите число a: ");
        scanf("%f", &value_a);
        printf("Введите число b: ");
        scanf("%f", &value_b);
        printf("Введите оператор(+,-,*,/): ");
        while (getchar() != '\n');
        scanf("%c", &operator_calc);
        switch (operator_calc){
            case '+': printf("%f", value_a + value_b); break;
            case '-': printf("%f", value_a - value_b); break;
            case '*': printf("%f", value_a * value_b); break;
            case '/': if (value_b != 0) {printf("%.2f", value_a / value_b);} else {printf("На ноль делить нельзя");}; break;
            default: printf("Неверный оператор"); break;
        }
        printf("\n");
    }
    printf("Прощай!...");
    return 0;
}