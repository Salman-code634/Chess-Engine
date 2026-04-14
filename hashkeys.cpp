// hashkeys.cpp

#include "defs.h"

U64 GeneratePosKey(const s_Board *pos)
{
    int sq = 0;
    U64 finalKey = 0;
    int piece = EMPTY;

    // Pieces
    for (sq = 0; sq < BRD_SQ_NUM; sq++)
    {
        piece = pos->pieces[sq];
        if (piece != NO_SQ && piece != EMPTY && piece != OFFBOARD)
        {
            ASSERT(piece >= wP && piece <= bK);
            finalKey ^= PieceKeys[piece][sq];
        }
    }

    // Side
    if (pos->side == WHITE)
    {
        finalKey ^= SideKey;
    }

    // EmPassant
    if (pos->enPas != NO_SQ)
    {
        ASSERT(pos->enPas >= 0 && pos->enPas < BRD_SQ_NUM);
        finalKey ^= PieceKeys[EMPTY][pos->enPas];
    }

    // CastlePerm
    ASSERT(pos->castlePerm >= 0 && pos->castlePerm <= 15);
    finalKey ^= CastleKeys[pos->castlePerm];

    return finalKey;
}
