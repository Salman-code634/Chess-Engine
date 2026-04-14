// io.cpp

#include <iostream>
#include "defs.h"
using std::cout;

// Print Square : e4
char *PrSq(const int sq)
{
    static char MvStr[3];

    int file = FilesBrd[sq];
    int rank = RanksBrd[sq];

    MvStr[0] = 'a' + file;
    MvStr[1] = '1' + rank;
    MvStr[2] = '\0';

    return MvStr;
}

// Print Move

char *PrMove(const int move)
{
    static char MvStr[6];

    int ff = FilesBrd[FROMSQ(move)];
    int rf = RanksBrd[FROMSQ(move)];
    int ft = FilesBrd[TOSQ(move)];
    int rt = RanksBrd[TOSQ(move)];

    int promoted = PROMOTED(move);

    if (promoted)
    {
        char pchar = 'q';
        if (IsKn(promoted))
        {
            pchar = 'n';
        }
        else if (IsRQ(promoted) && !IsBQ(promoted))
        {
            pchar = 'r';
        }
        else if (!IsRQ(promoted) && IsBQ(promoted))
        {
            pchar = 'b';
        }
        MvStr[0] = 'a' + ff;
        MvStr[1] = '1' + rf;
        MvStr[2] = 'a' + ft;
        MvStr[3] = '1' + rt;
        MvStr[4] = pchar;
        MvStr[5] = '\0';
    }
    else
    {
        MvStr[0] = 'a' + ff;
        MvStr[1] = '1' + rf;
        MvStr[2] = 'a' + ft;
        MvStr[3] = '1' + rt;
        MvStr[4] = '\0';
    }
    return MvStr;
}

void PrintMoveList(const s_MOVELIST *list)
{
    int index = 0;
    int move = 0;
    int score = 0;

    for (index = 0; index < list->count; index++)
    {
        move = list->moves[index].move;
        score = list->moves[index].score;

        cout << "Move:" << index + 1 << " > " << PrMove(move) << " (Score:" << score << ")\n";
    }
    cout << "Move List Total : " << list->count << "moves\n\n";
}
