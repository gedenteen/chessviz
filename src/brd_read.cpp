//#include <conio.h>
#include "brd_out.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

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

int brd_read(char board[9][9], int n, int m)
{
    FILE* inpt;
    inpt = fopen("input.txt", "r");
    int i, flag, lr1, ud1, lr2, ud2, numb = 0, check;
    char sg1[20], sg2[20], sg3[20], move[20];
    char fig1, fig2;
    while (!feof(inpt)) {
        fscanf(inpt, "%s", sg1);
        numb++;
        i = 0;
        if (feof(inpt))
            return 0;
        flag = 1;
        do {
            if (sg1[i] > '0' && sg1[i] < '9')
                i++;
            else
                flag = 0;
        } while (flag);
        if (sg1[i] != '.') {
            printf("неправильный вид входных данных, строка %d: в начале "
                   "строки должны быть число и точка после него, обозначающие "
                   "номер хода \n",
                   numb);
            return 1;
        }
        i++;
        fscanf(inpt, "%s", sg2);
        if (strcmp(sg2, "") == 0) {
            printf("неправильный вид входных данных, строка %d: информация "
                   "должна разделяться "
                   "пробелами \n",
                   numb);
            return 1;
        }
        i = 0;
        check = check_figure(sg2[i]);
        if (check == 3) {
            printf("неправильный вид входных данных, строка %d: неправильный "
                   "символ после первого пробела \n",
                   numb);
            return 1;
        } else if (check == 2) { //пешка
            fig1 = 'P';          //потмоу что ход белых
            lr1 = check_lr(sg2[i]);
            i++;
            ud1 = check_ud(sg2[i]);
        } else if (check == 1) { //не пешка
            fig1 = sg2[i];
            i++;
            lr1 = check_lr(sg2[i]);
            i++;
            ud1 = check_ud(sg2[i]);
        }
        if (lr1 == -1 || ud1 == -1) {
            printf("неправильный вид входных данных, строка %d: неправильные "
                   "начальные координаты для хода белых \n",
                   numb);
            return 1;
        }
        i++;
        if (sg2[i] != '-') {
            printf("неправильный вид входных данных, строка %d: ожидался "
                   "знак '-' \n",
                   numb);
            return 1;
        }
        i++;
        lr2 = check_lr(sg2[i]);
        i++;
        ud2 = check_ud(sg2[i]);
        if (lr2 == -1 || ud2 == -1) {
            printf("неправильный вид входных данных, строка %d: неправильные "
                   "завершающие координаты для хода белых \n",
                   numb);
            return 1;
        }
        if (board[ud1][lr1] == fig1) {
            board[ud2][lr2] = fig1;
            board[ud1][lr1] = ' ';
            memset(move, 0, 20);
            strcat(move, sg1);
            strcat(move, " ");
            strcat(move, sg2);
            strcat(move, "\n");
            brd_out(board, n, m, move);
        } else {
            printf("неправильный вид входных данных, строка %d: в указанном "
                   "поле нет заданной белой фигуры \n",
                   numb);
            return 1;
        }
        fscanf(inpt, "%s", sg3);
        /*if (strcmp(sg3, "") == 0) {
            printf("неправильный вид входных данных, строка %d: информация "
                   "должна разделяться пробелами \n", numb);
            return 1;
        } */ //теперь ход черных
        i = 0;
        check = check_figure(sg3[i]);
        if (check == 3) {
            printf("неправильный вид входных данных, строка %d: "
                   "неправильный символ после второго пробела \n",
                   numb);
            return 1;
        } else if (check == 2) { //пешка
            fig2 = 'p';          //потмоу что ход черных
            lr1 = check_lr(sg3[i]);
            i++;
            ud1 = check_ud(sg3[i]);
        } else if (check == 1) { //не пешка
            fig2 = black_change(sg3[i]);
            i++;
            lr1 = check_lr(sg3[i]);
            i++;
            ud1 = check_ud(sg3[i]);
        }
        if (lr1 == -1 || ud1 == -1) {
            printf("неправильный вид входных данных, строка %d: неправильные "
                   "начальные координаты для хода черных \n",
                   numb);
            return 1;
        }
        i++;
        if (sg3[i] != '-') {
            printf("неправильный вид входных данных, строка %d: ожидался "
                   "знак '-' \n",
                   numb);
            return 1;
        }
        i++;
        lr2 = check_lr(sg3[i]);
        i++;
        ud2 = check_ud(sg3[i]);
        if (lr2 == -1 || ud2 == -1) {
            printf("неправильный вид входных данных, строка %d: неправильные "
                   "завершающие координаты для хода черных \n",
                   numb);
            return 1;
        }
        if (board[ud1][lr1] == fig2) {
            board[ud2][lr2] = fig2;
            board[ud1][lr1] = ' ';
            memset(move, 0, 20);
            strcat(move, sg1);
            strcat(move, " ");
            strcat(move, sg3);
            strcat(move, "\n");
            brd_out(board, n, m, move);
        } else {
            printf("неправильный вид входных данных, строка %d: в указанном "
                   "поле нет заданной черной фигуры \n",
                   numb);
            return 1;
        }
    }
    return 0;
}
