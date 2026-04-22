// Perft.cpp

#include <iostream>
#include "defs.h"
using std ::cout;

long leafNodes;

void Perft(int depth, s_Board *pos)
{
    ASSERT(CheckBoard(pos));

    if (depth == 0)
    {
        leafNodes++;
        return;
    }

    s_MOVELIST list[1];
    GenerateAllMoves(pos, list);

    int MoveNum = 0;

    for (MoveNum = 0; MoveNum < list->count; MoveNum++)
    {
        if (!MakeMove(pos, list->moves[MoveNum].move))
        {
            continue;
        }
        Perft(depth - 1, pos);
        TakeMove(pos);
    }
    return;
}

void PerftTest(int depth, s_Board *pos)
{
    ASSERT(CheckBoard(pos));

    PrintBoard(pos);
    cout << "\nStarting test to Depth : " << depth << "\n";
    leafNodes = 0;

    s_MOVELIST list[1];
    GenerateAllMoves(pos, list);

    int move = 0;
    int MoveNum = 0;

    for (MoveNum = 0; MoveNum < list->count; MoveNum++)
    {
        move = list->moves[MoveNum].move;
        if (!MakeMove(pos, move))
        {
            continue;
        }
        long cumnodes = leafNodes;
        Perft(depth - 1, pos);
        TakeMove(pos);

        long oldnodes = leafNodes - cumnodes;
        cout << "Print Move " << MoveNum + 1 << " : " << PrMove(move) << " : " << oldnodes << "\n";
    }
    cout << "Test Completed : " << leafNodes << " nodes visited\n";
}
