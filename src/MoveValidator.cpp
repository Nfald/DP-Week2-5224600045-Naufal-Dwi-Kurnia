#include "MoveValidator.h"

bool MoveValidator::canPlay(const DominoTile& tile, const Board& board) const {
    if (board.isEmpty()) {
        return true;
    }

    int leftEnd = board.getLeftEnd();
    int rightEnd = board.getRightEnd();

    return tile.left == leftEnd || tile.right == leftEnd ||
           tile.left == rightEnd || tile.right == rightEnd;
}