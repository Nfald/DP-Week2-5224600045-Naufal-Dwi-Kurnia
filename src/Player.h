#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "DominoTile.h"

class Player {
private:
    std::string name;
    std::vector<DominoTile> hand;

public:
    Player();
    Player(const std::string& name);

    void addTile(const DominoTile& tile);
    void removeTile(int index);

    std::string getName() const;
    std::vector<DominoTile>& getHand();
    const std::vector<DominoTile>& getHand() const;

    bool hasNoTiles() const;
};

#endif