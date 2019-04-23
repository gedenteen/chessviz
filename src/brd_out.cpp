#include <stdio.h>

void brd_out(char board[9][9], int n, int m, char move[20])
{
    FILE* fl;
    if (move[0] == '0')
        fl = fopen("output.txt", "wt");
    else {
        fl = fopen("output.txt", "at");
        fputc('\n', fl);
        fputs(move, fl);
        fputc('\n', fl);
    }
    // ofstream outpt("output.txt");
    int i, u;
    for (i = 0; i < n; i++) {
        for (u = 0; u < m; u++) {
            fputc(board[i][u], fl);
            fputc(' ', fl);
            // outpt << board[i][u] << " "; // запись в файл
        }
        fputc('\n', fl);
    }
    fclose(fl);
}
