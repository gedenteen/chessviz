#include "brd_out.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

/*void brd_out(char board[9][9])
{
    ofstream outpt("output.txt");
    // создаём объект класса ofstream для записи
    int i, u;
    for (i = 0; i < 9; i++) {
        for (u = 0; u < 9; u++) {
            outpt << board[i][u] << " "; // запись в файл
        }
        outpt << endl;
    }
    outpt.close();
    // закрываем файл
} */

int main()
{
    setlocale(LC_ALL, "Russian");
    char board[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    brd_out(board);

    return 0;
}
