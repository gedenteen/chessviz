#include "brd_out.h"
#include "brd_read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 9, m = 9;
    char board[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char move[20] = {'0'};
    brd_out(board, n, m, move);
    FILE* inpt;
    inpt = fopen("input.txt", "r");
    char sg1[20], sg2[20], sg3[20];
    int i, flag, numb = 0, ret;
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
        ret = brd_read(board, n, m, sg2, 'w');
        if (ret)
            return 1;
        else {
            memset(move, 0, 20);
            strcat(move, sg1);
            strcat(move, " ");
            strcat(move, sg2);
            strcat(move, "\n");
            brd_out(board, n, m, move);
        }
        fscanf(inpt, "%s", sg3);
        if (feof(inpt)) //если нет хода черных
            return 0;   //выход
        ret = brd_read(board, n, m, sg3, 'b');
        if (ret)
            return 1;
        else {
            memset(move, 0, 20);
            strcat(move, sg1);
            strcat(move, " ");
            strcat(move, sg3);
            strcat(move, "\n");
            brd_out(board, n, m, move);
        }
    }
    return 0;
}
