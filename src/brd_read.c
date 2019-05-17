//#include "brd_out.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_figure(char ch)
{
    switch (ch) {
    case 'K': //не пешка
    case 'Q':
    case 'R':
    case 'N':
    case 'B':
        return 1;
        break;
    case 'P':
    case 'a': //пешка
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
        return 2;
        break;
    default:
        return 3;
        break;
    }
}
int check_ud(char ch)
{
    switch (ch) {
    case '8':
        return 0;
        break;
    case '7':
        return 1;
        break;
    case '6':
        return 2;
        break;
    case '5':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '3':
        return 5;
        break;
    case '2':
        return 6;
        break;
    case '1':
        return 7;
        break;
    default:
        return -1;
        break;
    }
}
int check_lr(char ch)
{
    switch (ch) {
    case 'a':
        return 1;
        break;
    case 'b':
        return 2;
        break;
    case 'c':
        return 3;
        break;
    case 'd':
        return 4;
        break;
    case 'e':
        return 5;
        break;
    case 'f':
        return 6;
        break;
    case 'g':
        return 7;
        break;
    case 'h':
        return 8;
        break;
    default:
        return -1;
        break;
    }
}
char black_change(char ch)
{
    switch (ch) {
    case 'K':
        ch = 'k';
        break;
    case 'Q':
        ch = 'q';
        break;
    case 'R':
        ch = 'r';
        break;
    case 'N':
        ch = 'n';
        break;
    case 'B':
        ch = 'b';
        break;
    }
    return ch;
}

int brd_read(char board[9][9], int n, int m, char* sg, char color)
{
    int i, lr1, ud1, lr2, ud2, numb = 0, check, typemove;
    char fig;
    i = 0;
    check = check_figure(sg[i]);
    if (check == 3) {
        printf("неправильный вид входных данных, строка %d: неправильный "
               "символ после первого пробела \n",
               numb);
        return 1;
    } else if (check == 2) { //пешка
        if (color == 'w')
            fig = 'P'; //потмоу что ход белых
        else
            fig = 'p';
        lr1 = check_lr(sg[i]);
        i++;
        ud1 = check_ud(sg[i]);
    } else if (check == 1) { //не пешка
        if (color == 'w')
            fig = sg[i];
        else
            fig = black_change(sg[i]);
        i++;
        lr1 = check_lr(sg[i]);
        i++;
        ud1 = check_ud(sg[i]);
    }
    if (lr1 == -1 || ud1 == -1) {
        printf("неправильный вид входных данных, строка %d: неправильные "
               "начальные координаты \n",
               numb);
        return 1;
    }
    i++;
    if (sg[i] == '-')
        typemove = 1; //тихий ход
    else if (sg[i] == 'x')
        typemove = 2; //взятие
    else {
        printf("неправильный вид входных данных, строка %d: ожидался "
               "знак '-' или 'x' \n",
               numb);
        return 1;
    }
    i++;
    lr2 = check_lr(sg[i]);
    i++;
    ud2 = check_ud(sg[i]);
    if (lr2 == -1 || ud2 == -1) {
        printf("неправильный вид входных данных, строка %d: неправильные "
               "завершающие координаты \n",
               numb);
        return 1;
    }
    if (board[ud1][lr1] == fig) {
        if (typemove == 1) {
            if (board[ud2][lr2] == ' ')
                board[ud2][lr2] = fig;
            else {
                printf("неправильный вид входных данных, строка %d: "
                       "указан тихий ход, но в заверщающем поле стоит "
                       "фигура \n",
                       numb);
                return 1;
            }
        } else { //взятие
            if (color == 'w') {
                if (board[ud2][lr2] == 'k' || board[ud2][lr2] == 'q'
                    || board[ud2][lr2] == 'r' || board[ud2][lr2] == 'n'
                    || board[ud2][lr2] == 'b' || board[ud2][lr2] == 'p')
                    board[ud2][lr2] = fig;
                else {
                    printf("неправильный вид входных данных, строка %d: "
                           "указано взятие, но в заверщающем поле нет фигуры "
                           "черных \n",
                           numb);
                    return 1;
                }

            } else { //ход черных
                if (board[ud2][lr2] == 'K' || board[ud2][lr2] == 'Q'
                    || board[ud2][lr2] == 'R' || board[ud2][lr2] == 'N'
                    || board[ud2][lr2] == 'B' || board[ud2][lr2] == 'P')
                    board[ud2][lr2] = fig;
                else {
                    printf("неправильный вид входных данных, строка %d: "
                           "указано взятие, но в заверщающем поле нет "
                           "фигуры белых \n",
                           numb);
                    return 1;
                }
            }
        }
        board[ud1][lr1] = ' ';
    } else {
        printf("неправильный вид входных данных, строка %d: в указанном "
               "начальном поле нет заданной фигуры \n",
               numb);
        return 1;
    }

    return 0;
}
