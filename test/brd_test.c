#include "brd_read.h"
#include "ctest.h"

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
CTEST(w_pawn, quiet_move_2)
{
    char board[9][9] = {{'8', 'r', 'n', 'b', ' ', ' ', ' ', 'n', 'r'},
                        {'7', 'p', 'p', 'p', ' ', 'P', ' ', 'p', 'p'},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'e', '7', '-', 'e', '8'};
    int ret = brd_read(board, 9, 9, sg, 'w');
    ASSERT_EQUAL(0, ret);
}
CTEST(w_pawn, quiet_wrong)
{
    char board[9][9] = {{'8', 'r', 'n', 'b', ' ', ' ', ' ', 'n', 'r'},
                        {'7', 'p', 'p', 'p', ' ', 'P', ' ', 'p', 'p'},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'e', '6', '-', 'e', '7'};
    int ret = brd_read(board, 9, 9, sg, 'w');
    ASSERT_EQUAL(1, ret);
}
CTEST(b_pawn, quiet_wrong)
{
    char board[9][9] = {{'8', 'r', 'n', 'b', ' ', 'p', ' ', 'n', 'r'},
                        {'7', 'p', 'p', 'p', ' ', 'P', ' ', 'p', 'p'},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'e', '8', '-', 'e', '9'};
    int ret = brd_read(board, 9, 9, sg, 'b');
    ASSERT_EQUAL(1, ret);
}
CTEST(w_pawn, take_move)
{
    char board[9][9] = {{'8', 'r', 'n', 'b', ' ', 'p', ' ', 'n', 'r'},
                        {'7', 'p', 'p', 'p', ' ', 'P', ' ', 'p', 'p'},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'e', '7', 'x', 'e', '8'};
    int ret = brd_read(board, 9, 9, sg, 'w');
    ASSERT_EQUAL(0, ret);
}
CTEST(b_pawn, take_move)
{
    char board[9][9] = {{'8', ' ', ' ', ' ', ' ', 'p', ' ', 'n', 'r'},
                        {'7', ' ', ' ', ' ', ' ', 'P', ' ', 'p', 'p'},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'b', '5', 'x', 'a', '4'};
    int ret = brd_read(board, 9, 9, sg, 'b');
    ASSERT_EQUAL(0, ret);
}
CTEST(b_pawn, take_wrong)
{
    char board[9][9] = {{'8', ' ', ' ', ' ', ' ', 'p', ' ', 'n', 'r'},
                        {'7', ' ', ' ', ' ', ' ', 'P', ' ', 'p', 'p'},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'b', '5', 'x', 'b', '4'};
    int ret = brd_read(board, 9, 9, sg, 'b');
    ASSERT_EQUAL(1, ret);
}
CTEST(b_rook, quiet_move)
{
    char board[9][9] = {{'8', ' ', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'R', 'h', '8', '-', 'h', '4'};
    int ret = brd_read(board, 9, 9, sg, 'b');
    ASSERT_EQUAL(0, ret);
}
CTEST(b_rook, take_move)
{
    char board[9][9] = {{'8', ' ', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'R', 'h', '8', 'x', 'e', '8'};
    int ret = brd_read(board, 9, 9, sg, 'b');
    ASSERT_EQUAL(0, ret);
}
CTEST(b_rook, take_wrong)
{
    char board[9][9] = {{'8', ' ', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'R', 'h', '8', 'x', 'd', '8'};
    int ret = brd_read(board, 9, 9, sg, 'b');
    ASSERT_EQUAL(1, ret);
}
CTEST(w_rook, quiet_move)
{
    char board[9][9] = {{'8', ' ', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'R', 'a', '1', '-', 'a', '3'};
    int ret = brd_read(board, 9, 9, sg, 'w');
    ASSERT_EQUAL(0, ret);
}
CTEST(w_knight, quiet_move)
{
    char board[9][9] = {{'8', ' ', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'N', 'b', '1', '-', 'c', '3'};
    int ret = brd_read(board, 9, 9, sg, 'w');
    ASSERT_EQUAL(0, ret);
}
CTEST(w_bishop, quiet_move)
{
    char board[9][9] = {{'8', ' ', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'B', 'c', '1', '-', 'a', '3'};
    int ret = brd_read(board, 9, 9, sg, 'w');
    ASSERT_EQUAL(0, ret);
}
CTEST(b_bishop, quiet_wrong)
{
    char board[9][9] = {{'8', ' ', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'B', 'a', '8', '-', 'c', '6'};
    int ret = brd_read(board, 9, 9, sg, 'b');
    ASSERT_EQUAL(1, ret);
}
CTEST(w_queen, quiet_move)
{
    char board[9][9] = {{'8', 'q', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'Q', 'd', '1', '-', 'd', '6'};
    int ret = brd_read(board, 9, 9, sg, 'w');
    ASSERT_EQUAL(0, ret);
}
CTEST(b_queen, take_move)
{
    char board[9][9] = {{'8', 'q', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'Q', 'a', '8', 'x', 'a', '4'};
    int ret = brd_read(board, 9, 9, sg, 'b');
    ASSERT_EQUAL(0, ret);
}
CTEST(w_king, queit_move)
{
    char board[9][9] = {{'8', 'q', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'K', 'e', '1', '-', 'e', '2'};
    int ret = brd_read(board, 9, 9, sg, 'w');
    ASSERT_EQUAL(0, ret);
}
CTEST(w_king, take_wrong)
{
    char board[9][9] = {{'8', 'q', ' ', ' ', ' ', 'P', ' ', ' ', 'r'},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char sg[] = {'K', 'e', '1', 'x', 'f', '1'};
    int ret = brd_read(board, 9, 9, sg, 'w');
    ASSERT_EQUAL(1, ret);
}
