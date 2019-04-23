//#include <conio.h>
#include "brd_out.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int brd_read(char board[9][9], int n, int m)
{
    FILE* inpt;
    inpt = fopen("input.txt", "r");
    int i, flag, lr1, up1, lr2, up2, numb = 0;
    char sg1[20], sg2[20], sg3[20], move[20];
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
            if (sg1[i] != '.') {
                printf(" код ошибки 1: номер хода указан неправильно: должны "
                       "быть число и точка после него \n");
                return 1;
            } else
                flag = 0;
        } while (flag);
        i++;
        fscanf(inpt, "%s", sg2);
        if (strcmp(sg2, "") == 0) {
            printf(" код ошибки 2: информация должна разделяться "
                   "пробелами \n");
            return 2;
        }
        i = 0;
        switch (sg2[i]) {
        case 'a':
            lr1 = 1;
            break;
        case 'b':
            lr1 = 2;
            break;
        case 'c':
            lr1 = 3;
            break;
        case 'd':
            lr1 = 4;
            break;
        case 'e':
            lr1 = 5;
            break;
        case 'f':
            lr1 = 6;
            break;
        case 'g':
            lr1 = 7;
            break;
        case 'h':
            lr1 = 8;
            break;
        default: {
            printf(" код ошибки 3: неправильно введено поле по "
                   "горизонтали: строка %d, символ: %c \n",
                   numb,
                   sg2[i]);
            return 3;
        }
        }
        i++;
        switch (sg2[i]) {
        case '1':
            up1 = 7;
            break;
        case '2':
            up1 = 6;
            break;
        case '3':
            up1 = 5;
            break;
        case '4':
            up1 = 4;
            break;
        case '5':
            up1 = 3;
            break;
        case '6':
            up1 = 2;
            break;
        case '7':
            up1 = 1;
            break;
        case '8':
            up1 = 0;
            break;
        default: {
            printf(" код ошибки 4: неправильно введено поле по "
                   "вертикали: строка %d, символ: %c \n",
                   numb,
                   sg2[i]);
            return 4;
        }
        }
        i++;
        if (sg2[i] != '-') {
            printf(" код ошибки 5: ожидался знак '-': строка %d, символ: %c \n",
                   numb,
                   sg2[i]);
            return 5;
        }
        i++;
        switch (sg2[i]) {
        case 'a':
            lr2 = 1;
            break;
        case 'b':
            lr2 = 2;
            break;
        case 'c':
            lr2 = 3;
            break;
        case 'd':
            lr2 = 4;
            break;
        case 'e':
            lr2 = 5;
            break;
        case 'f':
            lr2 = 6;
            break;
        case 'g':
            lr2 = 7;
            break;
        case 'h':
            lr2 = 8;
            break;
        default: {
            printf(" код ошибки 3: неправильно введено поле по "
                   "горизонтали: строка %d, символ: %c \n",
                   numb,
                   sg2[i]);
            return 3;
        }
        }
        i++;
        switch (sg2[i]) {
        case '1':
            up2 = 7;
            break;
        case '2':
            up2 = 6;
            break;
        case '3':
            up2 = 5;
            break;
        case '4':
            up2 = 4;
            break;
        case '5':
            up2 = 3;
            break;
        case '6':
            up2 = 2;
            break;
        case '7':
            up2 = 1;
            break;
        case '8':
            up2 = 0;
            break;
        default: {
            printf(" код ошибки 4: неправильно введено поле по "
                   "вертикали: строка %d, символ: %c \n",
                   numb,
                   sg2[i]);
            return 4;
        }
        }
        if (board[up1][lr1] == 'P' || board[up1][lr1] == 'p') {
            board[up2][lr2] = board[up1][lr1];
            board[up1][lr1] = ' ';
            memset(move, 0, 20);
            strcat(move, sg1);
            strcat(move, " ");
            strcat(move, sg2);
            strcat(move, "\n");
            brd_out(board, n, m, move);
        } else {
            printf(" код ошибки 6: в указанном поле нет пешки: строка %d \n",
                   numb);
            return 6;
        }
        fscanf(inpt, "%s", sg3);
        if (strcmp(sg3, "") == 0) {
            printf(" код ошибки 2: информация должна разделяться "
                   "пробелами \n");
            return 2;
        }
        i = 0;
        switch (sg3[i]) {
        case 'a':
            lr1 = 1;
            break;
        case 'b':
            lr1 = 2;
            break;
        case 'c':
            lr1 = 3;
            break;
        case 'd':
            lr1 = 4;
            break;
        case 'e':
            lr1 = 5;
            break;
        case 'f':
            lr1 = 6;
            break;
        case 'g':
            lr1 = 7;
            break;
        case 'h':
            lr1 = 8;
            break;
        default: {
            printf(" код ошибки 3: неправильно введено поле по "
                   "горизонтали: строка %d, символ: %c \n",
                   numb,
                   sg3[i]);
            return 3;
        }
        }
        i++;
        switch (sg3[i]) {
        case '1':
            up1 = 7;
            break;
        case '2':
            up1 = 6;
            break;
        case '3':
            up1 = 5;
            break;
        case '4':
            up1 = 4;
            break;
        case '5':
            up1 = 3;
            break;
        case '6':
            up1 = 2;
            break;
        case '7':
            up1 = 1;
            break;
        case '8':
            up1 = 0;
            break;
        default: {
            printf(" код ошибки 4: неправильно введено поле по "
                   "вертикали: строка %d, символ: %c \n",
                   numb,
                   sg3[i]);
            return 4;
        }
        }
        i++;
        if (sg3[i] != '-') {
            printf(" код ошибки 5: ожидался знак '-': строка %d, символ: %c \n",
                   numb,
                   sg3[i]);
            return 5;
        }
        i++;
        switch (sg3[i]) {
        case 'a':
            lr2 = 1;
            break;
        case 'b':
            lr2 = 2;
            break;
        case 'c':
            lr2 = 3;
            break;
        case 'd':
            lr2 = 4;
            break;
        case 'e':
            lr2 = 5;
            break;
        case 'f':
            lr2 = 6;
            break;
        case 'g':
            lr2 = 7;
            break;
        case 'h':
            lr2 = 8;
            break;
        default: {
            printf(" код ошибки 3: неправильно введено поле по "
                   "горизонтали: строка %d, символ: %c \n",
                   numb,
                   sg3[i]);
            return 3;
        }
        }
        i++;
        switch (sg3[i]) {
        case '1':
            up2 = 7;
            break;
        case '2':
            up2 = 6;
            break;
        case '3':
            up2 = 5;
            break;
        case '4':
            up2 = 4;
            break;
        case '5':
            up2 = 3;
            break;
        case '6':
            up2 = 2;
            break;
        case '7':
            up2 = 1;
            break;
        case '8':
            up2 = 0;
            break;
        default: {
            printf(" код ошибки 4: неправильно введено поле по "
                   "вертикали: строка %d, символ: %c \n",
                   numb,
                   sg3[i]);
            return 4;
        }
        }
        if (board[up1][lr1] == 'P' || board[up1][lr1] == 'p') {
            board[up2][lr2] = board[up1][lr1];
            board[up1][lr1] = ' ';
            memset(move, 0, 20);
            strcat(move, sg1);
            strcat(move, " ");
            strcat(move, sg3);
            strcat(move, "\n");
            brd_out(board, n, m, move);
        } else {
            printf(" код ошибки 6: в указанном поле нет пешки: строка %d \n",
                   numb);
            return 6;
        }
    }
    return 0;
}
