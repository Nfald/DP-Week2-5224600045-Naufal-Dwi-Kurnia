#include "Player.h"

Player::Player() : name("") {}

Player::Player(const std::string& name) : name(name) {}

void Player::addTile(const DominoTile& tile) {
    hand.push_back(tile);
}

void Player::removeTile(int index) {
    if (index >= 0 && index < static_cast<int>(hand.size())) {
        hand.erase(hand.begin() + index);
    }
}

std::string Player::getName() const {
    return name;
}

std::vector<DominoTile>& Player::getHand() {
    return hand;
}

const std::vector<DominoTile>& Player::getHand() const {
    return hand;
}

bool Player::hasNoTiles() const {
    return hand.empty();
}