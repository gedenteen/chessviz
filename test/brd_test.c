#include "ctest.h"
#include "brd_read.h"

CTEST(w_pawn, quiet_move)
{
  char board[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                      {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                      {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                      {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                      {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'e', '2', '-', 'e', '4'};
    int ret = brd_read(board, 9, 9, sg, 'w');
    ASSERT_EQUAL(0, ret);
}
CTEST(b_pawn, quiet_move)
{
  char board[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                      {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                      {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {'2', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                      {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                      {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'a', '7', '-', 'a', '5'};
    int ret = brd_read(board, 9, 9, sg, 'b');
    ASSERT_EQUAL(0, ret);
}
