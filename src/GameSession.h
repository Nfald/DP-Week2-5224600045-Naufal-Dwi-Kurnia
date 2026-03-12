#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <vector>
#include "Player.h"
#include "Board.h"
#include "MoveValidator.h"

class GameSession {
private:
    std::vector<Player> players;
    Board board;
    MoveValidator validator;
    int currentPlayerIndex;
    int round;
    int maxRounds;
    bool gameOver;

    void setupGame();
    void playTurn();
    bool tryPlayTile(Player& player);
    void passTurn(const Player& player) const;
    bool checkWinCondition() const;
    void advanceTurn();
    void printBoard() const;
    void printPlayerHand(const Player& player) const;

public:
    GameSession();
    void run();
};

#endif