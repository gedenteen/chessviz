#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

void brd_out(char board[9][9])
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
}
