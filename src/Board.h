#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "DominoTile.h"

class Board {
private:
    std::vector<DominoTile> tiles;

public:
    void setStartingTile(const DominoTile& tile);
    bool isEmpty() const;

    int getLeftEnd() const;
    int getRightEnd() const;

    void placeTile(const DominoTile& tile);
    const std::vector<DominoTile>& getTiles() const;
};

#endif