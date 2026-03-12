#include "Board.h"

void Board::setStartingTile(const DominoTile& tile) {
    tiles.push_back(tile);
}

bool Board::isEmpty() const {
    return tiles.empty();
}

int Board::getLeftEnd() const {
    return tiles.front().left;
}

int Board::getRightEnd() const {
    return tiles.back().right;
}

void Board::placeTile(const DominoTile& tile) {
    if (tiles.empty()) {
        tiles.push_back(tile);
        return;
    }

    int leftEnd = getLeftEnd();
    int rightEnd = getRightEnd();

    if (tile.right == leftEnd) {
        tiles.insert(tiles.begin(), tile);
    } else if (tile.left == leftEnd) {
        DominoTile flipped = {tile.right, tile.left};
        tiles.insert(tiles.begin(), flipped);
    } else if (tile.left == rightEnd) {
        tiles.push_back(tile);
    } else if (tile.right == rightEnd) {
        DominoTile flipped = {tile.right, tile.left};
        tiles.push_back(flipped);
    }
}

const std::vector<DominoTile>& Board::getTiles() const {
    return tiles;
}