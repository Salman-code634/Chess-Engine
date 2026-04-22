#include <iostream>
#include <cstdlib>
#include "defs.h"
using std::cout;

#define PERFTFEN "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1"

int main()
{
    AllInit();

    s_Board board[1];
    s_MOVELIST list[1];

    ParseFen(Start_FEN, board);
    PerftTest(3, board);

    

    return 0;
}