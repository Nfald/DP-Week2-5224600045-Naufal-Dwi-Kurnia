#ifndef MOVE_VALIDATOR_H
#define MOVE_VALIDATOR_H

#include "DominoTile.h"
#include "Board.h"

class MoveValidator {
public:
    bool canPlay(const DominoTile& tile, const Board& board) const;
};

#endif