// Validate.cpp

#include "defs.h"

int SqOnBoard(const int sq)
{
    if (FilesBrd[sq] == OFFBOARD)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int SideValid(const int side)
{
    if (side == WHITE || side == BLACK)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int FileRankValid(const int fr)
{
    if (fr >= 0 && fr <= 7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int PieceValidEmpty(const int pce)
{
    if (pce >= EMPTY && pce <= bK)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int PieceValid(const int pce)
{
    if (pce >= wP && pce <= bK)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

