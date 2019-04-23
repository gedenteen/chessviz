#include "brd_out.h"
#include "brd_read.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 9, m = 9;
    // char** board;
    // board = new char*[n];
    // for (int i = 0; i < n; i++) {
    //    board[i] = new char[m];
    //}
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
    brd_read(board, n, m);
    return 0;
}
